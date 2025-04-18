#ifndef LAB03_H
#define LAB03_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
# include <unistd.h>

typedef struct count
{
	int comp;
	int swaps;
} t_count;

typedef struct pos
{
	int start;
	int mid;
	int end;
} t_pos;

typedef struct algos
{
	char *name;
	void (*function)(int *, t_pos *, t_count *);
} t_algos;

/* ----- Modifiable Macros ----- */
#  define ORDER 2	// 0 for ascending, 1 for descending, 2 for random
#  define SIZE 100	// size of the array

/* ----- Non-Modfiable Macros ----- */

/* Monotonic system-wide clock.  */
# ifndef CLOCK_MONOTONIC
#  define CLOCK_MONOTONIC 1
# endif

# define ASCENDING 0
# define DESCENDING 1
# define RANDOM 2

/*	array_aux.c */
void	copy_array_pos(int *src, int **dest, int start, int end);
void	copy_array(int *src, int **dest, int size);
int		is_sorted(int *arr);
int *	generate_array();
void	print_array(int *arr, int size);


/*	Algothims	*/
void	swap(int *a, int *b, int *troca);
void	mergeSort(int *arr, t_pos *pos, t_count *count);
void	quickSort(int *arr, t_pos *pos, t_count *count);

#endif