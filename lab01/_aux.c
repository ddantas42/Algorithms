#include "lab01.h"

/** 
 * Checks if a given integer array is sorted
 * @param arr	Array to check if is sorted
 * @param n 	The size of the array
 * @returns 	1 if it is sorted, 0 if it isn't sorted 
 */
int is_sorted(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 0;
	}
	return 1;
}

/**
 * Runs the algorithm and prints the time elapsed and the index of the element
 * @param arr	Array to search the index
 * @param size 	The size of the array
 * @param elem  The value we are searching for in the array
 * @param algorithm  The algorithm to run as function pointer
 * @details 	We use clock_gettime to measure the time elapsed in nano seconds so it's more precise
 */
void run_algorithm(int *arr, int size, int elem, int (*algorithm)(int *, int, int))
{
	struct timespec start, end;
	int index = -1;
	
	clock_gettime(CLOCK_MONOTONIC, &start);
	index = algorithm(arr, size, elem);
	clock_gettime(CLOCK_MONOTONIC, &end);

	long ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
	printf("time elapsed: %ld nano seconds\n", ns);
	if (index == -1)
		printf("Element not found\n");
	else
		printf("Element %d at index: %d\n", elem, index);

}