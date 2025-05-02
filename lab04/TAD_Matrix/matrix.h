#ifndef MATRIX_H
# define MATRIX_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_matrix { 
	int		lin;  
	int		col;  
	float	*v; 
} Matrix; 


Matrix	*mat_create(int m, int n); 
void	mat_free(Matrix *mat);  
float	mat_access_element(Matrix *mat, int i, int j);  
void	mat_assign_element(Matrix *mat, int i, int j, float v);  
int		mat_lines(Matrix *mat);  
int		mat_columns(Matrix *mat); 
int		*mat_great_multiplication_order(int *dimensoes);

#endif