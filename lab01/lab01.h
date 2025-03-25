#ifndef LAB01_H
#define LAB01_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <unistd.h>

/*	_aux.c		*/
int		is_sorted(int arr[], int n);
void	run_algorithm(int *arr, int size, int elem, int (*algorithm)(int *, int, int));

/*	init.c		*/
int		get_array_size();
int		*declare_manual_array(int size);
int		*declare_automatic_array(int size, char *argv[]);
int		 *init_array(int argc, char *argv[], int *size);

/*	G8_lab01.c */
int		procura_sequencial(int arr[], int n, int elem);
int		procura_binaria(int arr[], int n, int elem);

#endif
