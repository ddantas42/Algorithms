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

int		*mat_great_multiplication_order(int *dimensoes)
{
	return 0;
}
