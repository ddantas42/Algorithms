#include "../inc/lab02.h"

// Simple function to print the stats of the algorithm
static void	print_stats(int *arr, long time_ns, int swaps, int comparisons)
{
	printf("time elapsed: %ld nano seconds \n", time_ns);
	printf("swaps: %d\n", swaps);
	printf("comparisons: %d\n", comparisons);

	if (is_sorted(arr) == 1)
		printf("Array sorted\n");
	else
	{
		printf("Array not sorted\n");
		print_array(arr);
	}

}

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
	long time_ns = 0;

	clock_gettime(CLOCK_MONOTONIC, &start);
	algorithm(arr, SIZE, &swaps, &comparisons);
	clock_gettime(CLOCK_MONOTONIC, &end);
	time_ns = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
	
	print_stats(arr, time_ns, swaps, comparisons);
}

static int sizeof_algos(t_algos *algos)
{
	int i = 0;
	while (algos[i].name != NULL)
		i++;
	return (i);
}

int main()
{

	t_algos algos[] = { // If you want to test your own, just add it here or comment others to filter the output
		{"Bubble Sort", &bubble_sort},
		{"Bubble Sort Optimized", &bubble_sort_opt},
		{"Bubble Sort Optimized V2", &bubble_sort_opt_v2},
		{"Selection Sort", &selection_sort},
		{"Insertion Sort", &insertion_sort},
		{NULL, NULL} // End of the array, keep this at the end always if you modify the struct
	};
	int algos_size = sizeof_algos(algos);
	
	int *arr = generate_array(ORDER);
	int *arr_copy = NULL;

	print_array(arr);
	for (int i = 0; i < algos_size; i++)
	{
		printf("\n---- %s ----\n", algos[i].name);
		copy_array(arr, &arr_copy);
		run_algorithm(arr_copy, algos[i].function);
		free(arr_copy), arr_copy = NULL;
	}
	free(arr);

	return (0);
}