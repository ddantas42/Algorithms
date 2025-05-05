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
 * @return value at the specified position
 */
float	mat_access_element(Matrix *mat, int i, int j)
{
	if (i < 0 || j < 0 || i >= mat->lin || j >= mat->col)
	{
		printf("mat_access_element: Index out of bounds\n");
		return 0;
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

static void print_mat(long **m, int n, int m_size)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m_size; j++)
		{
			printf("%ld ", m[i][j]);
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
static void compute_tables(int *Dim, int n, long **m, long **s)
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
				long cost = m[i][k] + m[k + 1][j] + Dim[i] * Dim[k + 1] * Dim[j + 1]; // Cost of multiplying matrices i..k and k+1..j
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
 * Builds the multiplication order from the split table using a loop-based simulation
 * @param s split index table filled by compute_tables
 * @param n number of matrices in the chain
 * @return an array of length n - 1 indicating the split order (post-order traversal)
 */
static int *generate_order_from_s(long **s, int n)
{
	int *order = malloc((n - 1) * sizeof(int));
	int top = -1;

	// Simulate a stack of [i, j] ranges to process
	typedef struct { int i, j; int visited; } Frame;
	Frame *stack = malloc(n * n * sizeof(Frame));

	stack[++top] = (Frame){0, n - 1, 0};
	int pos = 0;

	while (top >= 0)
	{
		Frame *curr = &stack[top];

		if (curr->i == curr->j)
		{
			top--;  // Leaf matrix, no split
			continue;
		}

		if (curr->visited == 0)
		{
			// Go left first
			curr->visited = 1;
			stack[++top] = (Frame){curr->i, s[curr->i][curr->j], 0};
		}
		else if (curr->visited == 1)
		{
			// Then go right
			curr->visited = 2;
			stack[++top] = (Frame){s[curr->i][curr->j] + 1, curr->j, 0};
		}
		else
		{
			// Then store the split
			order[pos++] = s[curr->i][curr->j];
			top--;
		}
	}

	free(stack);
	return order;
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
	while (Dim[n + 1]) n++;  // Count matrices based on non-zero Dim entries

	long **m = (long **)malloc(n * sizeof(long *));
	long **s = (long **)malloc(n * sizeof(long *));
	for (long i = 0; i < n; i++)
	{
		m[i] = (long *)malloc(n * sizeof(long));
		s[i] = (long *)malloc(n * sizeof(long));
	}

	compute_tables(Dim, n, m, s);
	int *order = generate_order_from_s(s, n);

	for (int i = 0; i < n; i++)
	{
		free(m[i]);
		free(s[i]);
	}
	free(m);
	free(s);

	return order;
}