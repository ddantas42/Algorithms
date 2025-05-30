#ifndef FILE_H
# define FILE_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define RESET   "\033[0m"

typedef struct s_algos
{
	int		*vector;
	int		*hashTable;
	int		hashTableSize;
	double	searchsTime[2];

} t_algos;

# define LOAD_FACTOR 2
# define NOT_FOUND  -1

int		hash(int key, int size);
void	insertHash(int *hashTable, int size, int key);
int		searchHash(int *hashTable, int size, int key);
int		binarySearch(int *arr, int n, int key);


#endif