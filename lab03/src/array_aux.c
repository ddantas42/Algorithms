#include "../inc/lab03.h"

int copy_array_pos(int *src, int **dest, int start, int end)
{
	*dest = (int *)malloc((end - start + 1) * sizeof(int));
	if (*dest == NULL)
	{
		printf("Memory allocation failed\n");
		printf("Error copying array\n");
		free(src);
		exit(1);
	}
	for (int i = start; i <= end; i++)
		(*dest)[i - start] = src[i];

	return (0);
}

int copy_array(int *src, int **dest, int size)
{
	*dest = (int *)malloc(size * sizeof(int));
	if (*dest == NULL)
	{
		printf("Memory allocation failed\n");
		printf("Error copying array\n");
		free(src);
		exit(1);
	}
	for (int i = 0; i < size; i++)
		(*dest)[i] = src[i];
}

/**
 * Checks if the array is sorted
 * @param arr  The array to check
 * @return  1 if the array is sorted, 0 otherwise
 */
int is_sorted(int *arr)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

/**
 * Shuffles the array using the Fisher-Yates algorithm
 * @param arr  The array to shuffle
 * @param n    The size of the array
 */
static void shuffle(int *arr)
{
	int j = 0;
	
	srand(time(NULL));
	for (int i = SIZE - 1; i > 0; i--)
	{
		j = rand() % (i + 1);
		swap(&arr[i], &arr[j], NULL);
	}
}

/**
 * Generates an array of size 'size' with the elements in ascending or descending order
 * according to the ORDER macro and SIZE macro
 * @return  The generated array
 */
int *generate_array(int order)
{
	int *array = (int *)malloc(SIZE * sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	for (int i = 0; i < SIZE; i++)
		array[i] = order == ASCENDING ? i : SIZE - i;
	if (order == RANDOM)
		shuffle(array);
	return (array);
}

/**
 * Prints the array
 * @param arr  The array to print
 */
void print_array(int *arr)
{
	printf("Array: [ ");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("]\n");
}