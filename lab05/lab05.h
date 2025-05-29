#ifndef FILE_H
# define FILE_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>


# define LOAD_FACTOR 2
# define NOT_FOUND -1

int hash(int key, int size);
void insertHash(int *hashTable, int size, int key);
int searchHash(int *hashTable, int size, int key);
int binarySearch(int *arr, int n, int key);


#endif