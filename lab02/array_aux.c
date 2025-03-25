#include "lab02.h"

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
 * Generates an array of size 'size' with the elements in ascending or descending order
 * according to the ORDER macro and SIZE macro
 * @return  The generated array
 */
int *generate_array()
{
	int *array = (int *)malloc(SIZE * sizeof(int));
	if (array == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	
	for (int i = 0; i < SIZE; i++)
		if (ORDER == 0)
			array[i] = i;
		else
			array[i] = SIZE - i;
			
	return (array);
}

/**
 * Prints the array
 * @param arr  The array to print
 */
void print_array(int *arr)
{
	for (int i = 0; i < SIZE; i++)
		printf("%d ", arr[i]);
	printf("\n");
}