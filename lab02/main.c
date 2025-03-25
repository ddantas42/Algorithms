#include "lab02.h"

/**
 * Runs the algorithm and prints the time elapsed and the index of the element
 * @param arr   Array to search the index
 * @param size  The size of the array
 * @param elem  The value we are searching for in the array
 * @param algorithm  The algorithm to run as function pointer
 * @details     We use clock_gettime to measure the time elapsed in nano seconds so it's more precise
 */
static void	run_algorithm(int *arr, void (*algorithm)(int *, int, int *, int *))
{
	struct timespec start, end;
	int swaps = 0, comparisons = 0;

	clock_gettime(CLOCK_MONOTONIC, &start);
	algorithm(arr, SIZE, &swaps, &comparisons);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	long ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
	printf("time elapsed: %ld nano seconds \n", ns);
	printf("swaps: %d\n", swaps);
	printf("comparisons: %d\n", comparisons);
	if (is_sorted(arr))
		printf("Array sorted\n");
	else
		printf("Array not sorted\n");
	
}

int main()
{
	int *arr = NULL;
	void (*functions[4])(int *, int, int *, int *) = {&bubble_sort, &bubble_sort_opt, &selection_sort, &insertion_sort};
	char *names[4] = {"Bubble Sort", "Bubble Sort Optimized", "Selection Sort", "Insertion Sort"};

	for (int i = 0; i < 4; i++)
	{
		printf("\n---- %s ----\n", names[i]);
		arr = generate_array();
		run_algorithm(arr, functions[i]);
		free(arr);
	}

	return (0);
}