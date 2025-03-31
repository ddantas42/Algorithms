#include "lab02.h"

long double total_swaps = 0;
long long total_comparisons = 0;
long long total_time = 0;


// Simple function to print the stats of the algorithm
static void	print_stats(int *arr, long time_ns, int swaps, int comparisons)
{
	printf("time elapsed: %ld nano seconds \n", time_ns);
	printf("swaps: %d\n", swaps);
	printf("comparisons: %d\n", comparisons);

	if (is_sorted(arr) == 1)
		printf("Array sorted\n");
	else
		printf("Array not sorted\n");

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
	
	// print_stats(arr, time_ns, swaps, comparisons);
	// print_array(arr);

	if (is_sorted(arr) == 0)
	{
		printf("Array not sorted\n");
		exit(1);
	}

	total_swaps += (double)swaps / 10000;
	total_comparisons += comparisons / 10000;
	total_time += time_ns / 10000;
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
	/*
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
*/

	int *arr = NULL;

	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < 10000; i++)
	{
		arr = generate_array(ORDER);
		run_algorithm(arr, &selection_sort);
		free(arr),arr = NULL;
		printf("[%.1f%%] Run %d | Swaps %.2Lf | Comparions %lld | time %lld\r", (double)(i + 1) / 100 ,i + 1, total_swaps, total_comparisons, total_time);
		fflush(stdout);
	}
	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("\n\n\n");
	printf("Average swaps: %Lf\n", total_swaps);
	printf("Average comparisons: %lld\n", total_comparisons);
	printf("Average time: %lld nano seconds\n", total_time);
	printf("Total Time taken: %ld seconds\n", (end.tv_sec - start.tv_sec));
	return (0);
}