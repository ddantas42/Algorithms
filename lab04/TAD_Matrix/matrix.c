#include "matrix.h"

/**
 * Will create a matrix with M lines and N columns
 * @param m number of lines in the matrix
 * @param n number of columns in the matrix
 * @return a Matrix pointer with lines, columns and a vector associated
*/
Matrix	*mat_create(int m, int n)
{
	Matrix *new_mat = NULL;

	if (m <= 0 || n <= 0)
	{
		printf("mat_create: lines and columns must be greater than 0\n");
		return NULL;
	}
	
	new_mat = (Matrix *)malloc(sizeof(Matrix));
	if (new_mat == NULL)
		return NULL;

	new_mat->v = (float *)calloc(m * n, sizeof(float));
	if (new_mat->v == NULL)
	{
		free(new_mat);
		return NULL;
	}

	new_mat->lin = m;
	new_mat->col = n;

	return new_mat;
}

/**
 * Frees the memory allocated for a matrix
 * @param mat pointer to the matrix to be freed
 */
void	mat_free(Matrix *mat)
{
	if (mat == NULL)
		return ;

	if (mat->v != NULL)
		free(mat->v);
	free(mat);
}

/**
 * Returns the value of the element at position [i][j] in the matrix
 * @param mat pointer to the matrix
 * @param i row index
 * @param j column index
 * @return value at the specified position, or -1 if out of bounds
 */
float	mat_access_element(Matrix *mat, int i, int j)
{
	if (i < 0 || j < 0 || i >= mat->lin || j >= mat->col)
	{
		printf("mat_access_element: Index out of bounds\n");
		return -1;
	}
	return (mat->v[(i * mat->col) + j]);

} 

/**
 * Assigns a value to the element at position [i][j] in the matrix
 * @param mat pointer to the matrix
 * @param i row index
 * @param j column index
 * @param v value to assign
*/
void	mat_assign_element(Matrix *mat, int i, int j, float v)
{
	if (i < 0 || j < 0 || i >= mat->lin || j >= mat->col)
	{
		printf("mat_assign_element: Index out of bounds\n");
		return ;
	}
	mat->v[(i * mat->col) + j] = v;
}  

/**
 * Returns the number of lines in the matrix
 * @param mat pointer to the matrix
 * @return number of lines
 */
int		mat_lines(Matrix *mat)
{
	return mat->lin;
}

/**
 * Returns the number of columns in the matrix
 * @param mat pointer to the matrix
 * @return number of columns
 */
int		mat_columns(Matrix *mat)
{
	return mat->col;
} 

static void print_mat(int **m, int n, int m_size)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/** 
 * Fills dynamic programming tables with minimum multiplication costs and split points
 * @param Dim array with dimensions of the matrices [d0, d1, ..., dn]
 * @param n number of matrices (n = length of Dim - 1)
 * @param m table to store minimal multiplication costs from i to j
 * @param s table to store optimal split index between matrix i and j
 */
static void compute_tables(int *Dim, int n, int **m, int **s)
{
	for (int i = 0; i < n; i++)
		m[i][i] = 0;

	for (int len = 2; len <= n; len++)
	{
		for (int i = 0; i <= n - len; i++)
		{
			int j = i + len - 1;
			m[i][j] = INT_MAX; // Initialize to a large value
			for (int k = i; k < j; k++)
			{
				int cost = m[i][k] + m[k + 1][j] + Dim[i] * Dim[k + 1] * Dim[j + 1]; // Cost of multiplying matrices i..k and k+1..j
				if (cost < m[i][j])
				{
					m[i][j] = cost;
					s[i][j] = k;
				}
			}
		}
	}
	print_mat(m, n, n);
	print_mat(s, n, n);
}

/**
 * Determines the optimal multiplication order for a chain of matrices
 * by reconstructing the sequence of splits from the split index table.
 * This function simulates the post-order traversal of the optimal
 * parenthesization tree using a loop-based approach.
 * 
 * @param s A 2D array representing the split index table, where s[i][j]
 *          indicates the index of the split for the subproblem involving
 *          matrices i through j.
 * @param i The start index of the current subproblem.
 * @param j The end index of the current subproblem.
 * @param steps An array to store the split indices for the optimal
 * 		    multiplication order.
 * @param current_step A pointer to the current step in the multiplication
 *          order. It is incremented as splits are assigned.
 *          This is used to track the current step in the
 *          multiplication order.
 * @return An array of size n - 1, where each element represents the
 *         index of a split in the optimal multiplication order.
 */
static void assign_steps(int **s, int i, int j, int *steps, int *current_step)
{
	if (i == j)
		return;

	int k = s[i][j];

	// Recursively assign steps for the left and right subproblems first
	assign_steps(s, i, k, steps, current_step);
	assign_steps(s, k + 1, j, steps, current_step);

	// Assign the current step to the split point
	steps[k] = (*current_step);
	(*current_step)++; // Increment the step after assigning
}

/** 
 * Will return the order of multiplications the matrix should be multiplied 
 * for less computing efforts using dynamic programming
 * @param Dim array with the dimensions of the matrices (without repeating columns)\n
 * I.e A 8*4 * B 4*3 * C 3*5 = [8, 4, 3, 5]
 * @return an array with the order of multiplication represented by split positions
 * Each entry is the index (k) where the optimal multiplication splits the matrix chain\n
 * I.e (A*B)*C = [0, 1] | A*(B*C) = [1, 0]
 * The returned array has length n - 1, where n is the number of matrices
 */
int *mat_great_multiplication_order(int *Dim)
{
	int n = 0;
	if (!Dim)
		return NULL;
	while (Dim[n]) n++;  // Count matrices based on non-zero Dim entries

	int **m = (int **)malloc(n * sizeof(int *));
	int **s = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		m[i] = (int *)malloc(n * sizeof(int));
		s[i] = (int *)malloc(n * sizeof(int));
	}

	compute_tables(Dim, n, m, s);
	int *steps = calloc(n, sizeof(int));
	int current_step = 1;
	assign_steps(s, 0, n - 1, steps, &current_step);

	for (int i = 0; i < n; i++)
	{
		free(m[i]);
		free(s[i]);
	}
	free(m);
	free(s);

	return steps;
}