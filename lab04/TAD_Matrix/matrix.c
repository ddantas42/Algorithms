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


static int multiplications(int linha, int comum, int coluna) 
{
	return linha * coluna * comum;
}

/** 
 * Will return the order of multiplications the matrix should be multiplied 
 * for less computing efforts
 * @param Dim array with the dimensions of the matrix (without repeating columns)\n
I.e A 8*4 * B 4*3 * C 3*5 = [8, 4, 3, 5]
 * @return an array with the order of multiplication
I.e (A*B)*C = [0, 1, 2] | A*(B*C) = [0, 2, 1]
  */
// int		*mat_great_multiplication_order(int *Dim)
// {
// 	int multiplica1 = multiplications(Dim[0], Dim[1], Dim[2]);
// 	int multiplica2 = multiplications(Dim[0], Dim[2], Dim[3]);
// 	int total1 = multiplica1 + multiplica2;
// 	printf("multiplica1 = %d\n", multiplica1);
// 	printf("multiplica2 = %d\n", multiplica2);
// 	printf("total1 = %d\n", total1);

// 	multiplica1 = multiplications(Dim[1], Dim[2], Dim[3]);
// 	multiplica2 = multiplications(Dim[0], Dim[1], Dim[3]);
// 	int total2 = multiplica1 + multiplica2;

// 	printf("multiplica1 = %d\n", multiplica1);
// 	printf("multiplica2 = %d\n", multiplica2);
// 	printf("total2 = %d\n", total2);
	
// 	int *order = (int *)malloc(3 * sizeof(int));
// 	if (total1 < total2)
// 		order[0] = 0, order[1] = 1, order[2] = 2;
// 	else
// 		order[0] = 1, order[1] = 2, order[2] = 0;
		
// 	return order;

// }

// Helper function to fill the DP tables
void compute_optimal_order(int *Dim, int n, int **m, int **s) {
	for (int i = 0; i < n; i++)
		m[i][i] = 0;

	for (int chain_len = 2; chain_len <= n; chain_len++)
	{
		for (int i = 0; i <= n - chain_len; i++)
		{
			int j = i + chain_len - 1;
			m[i][j] = 999999999;

			for (int k = i; k < j; k++)
			{
				int cost = m[i][k] + m[k+1][j] + Dim[i] * Dim[k+1] * Dim[j+1];
				if (cost < m[i][j])
				{
					m[i][j] = cost;
					s[i][j] = k;
				}
			}
		}
	}
}

// Recursive traversal to fill order array
void build_order(int **s, int i, int j, int *order, int *pos) {
	if (i == j)
		return;

	int k = s[i][j];
	build_order(s, i, k, order, pos);
	build_order(s, k + 1, j, order, pos);

	order[*pos] = k;
	(*pos)++;
}

// Main function to be called
int *mat_great_multiplication_order(int *Dim, int num_matrices) {
	int n = num_matrices;  // Number of matrices
	int **m = malloc(n * sizeof(int *));
	int **s = malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		m[i] = malloc(n * sizeof(int));
		s[i] = malloc(n * sizeof(int));
	}

	compute_optimal_order(Dim, n, m, s);

	int *order = malloc((n - 1) * sizeof(int));
	int pos = 0;
	build_order(s, 0, n - 1, order, &pos);

	// Free DP tables
	for (int i = 0; i < n; i++) {
		free(m[i]);
		free(s[i]);
	}
	free(m);
	free(s);

	return order;
}

