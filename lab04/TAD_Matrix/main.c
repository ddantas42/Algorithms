#include "matrix.h"

int main()
{
	Matrix * mat = mat_create(2, 2);

	int dimensoes[6] = {1, 1, 1, 1, 1, 1};
	int *ordem = mat_great_multiplication_order(dimensoes);

	printf("Ordem de multiplicação: %d %d %d\n", ordem[0], ordem[1], ordem[2]);
	free(ordem);

	if (mat == NULL)
		return 1;
	
	/*
	Assigning names to matrix
			| 1 2 |
			| 3 4 |
	*/ 
	mat_assign_element(mat, 0, 0, 1.0);
	mat_assign_element(mat, 0, 1, 2.0);
	mat_assign_element(mat, 1, 0, 3.0);
	mat_assign_element(mat, 1, 1, 4.0);

	printf("created matrix[0, 0] = %.1f\n", mat_access_element(mat, 0, 0));
	printf("created matrix[0, 1] = %.1f\n", mat_access_element(mat, 0, 1));
	printf("created matrix[1, 0] = %.1f\n", mat_access_element(mat, 1, 0));
	printf("created matrix[1, 1] = %.1f\n", mat_access_element(mat, 1, 1));

	printf("Matrix lines = %d\n", mat_lines(mat));
	printf("Matrix columns = %d\n", mat_columns(mat));
	
	mat_free(mat);
}