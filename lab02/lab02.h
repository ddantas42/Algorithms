#ifndef LAB02_H
#define LAB02_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <unistd.h>

typedef struct algos
{
	char *name;
	void (*function)(int *, int, int *, int *);
} t_algos;

/* ----- Modifiable Macros ----- */
#  define ORDER 0 // 0 for ascending, 1 for descending, 2 for random
#  define SIZE 4 // size of the array

/* ----- Non-Modfiable Macros ----- */

/* Monotonic system-wide clock.  */
# ifndef CLOCK_MONOTONIC
#  define CLOCK_MONOTONIC 1
# endif

# define ASCENDING 0
# define DESCENDING 1
# define RANDOM 2

/*	array_aux.c */
int		copy_array(int *src, int **dest);
int		is_sorted(int *arr);
int *	generate_array();
void	print_array(int *arr);

/*	Algothims	*/
void	swap(int *a, int *b, int *troca);

void	bubble_sort(int arr[], int n, int *troca, int *comp);

void	bubble_sort_opt(int arr[], int n, int *troca, int *comp);
void	bubble_sort_opt_v2(int arr[], int n, int *troca, int *comp);

void	selection_sort(int arr[], int n, int *troca, int *comp);
void	selection_sort_v2(int arr[], int n, int *troca, int *comp);

void	insertion_sort(int arr[], int n, int *troca, int *comp);

#endif