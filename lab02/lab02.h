#ifndef LAB02_H
#define LAB02_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <unistd.h>

/* Monotonic system-wide clock.  */
# ifndef CLOCK_MONOTONIC
#  define CLOCK_MONOTONIC 1
# endif

# ifndef ORDER
#  define ORDER 1 // 0 for ascending, 1 for descending
# endif

# ifndef SIZE
#  define SIZE 1e3 // size of the array
# endif

/*	array_aux.c */
int		is_sorted(int *arr);
int *	generate_array();
void	print_array(int *arr);

/*	Algothims	*/
void	bubble_sort(int arr[], int n, int *troca, int *comp);
void	bubble_sort_opt(int arr[], int n, int *troca, int *comp);
void	selection_sort(int arr[], int n, int *troca, int *comp);
void	insertion_sort(int arr[], int n, int *troca, int *comp);

#endif