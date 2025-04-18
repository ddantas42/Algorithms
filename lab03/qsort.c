#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef CLOCK_MONOTONIC
# define CLOCK_MONOTONIC 1
#endif

// Compare function for qsort
int compare_ints(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Function to get elapsed time in nanoseconds
long get_elapsed_ns(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
}

/**
 * Function to run qsort on two arrays: one sorted in ascending order and the other in descending order.
 * It measures the time taken to sort both arrays and prints the results.
 * @param n The size of the arrays to be sorted.
*/
void run_qsort_test(int n)
{
    int* asc 	= malloc(n * sizeof(int));
    int* desc	= malloc(n * sizeof(int));
    if (!asc || !desc)
	{
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < n; i++) 
	{
        asc[i] = i + 1;
        desc[i] = n - i;
    }

    struct timespec start, end;

    // Sort ascending array
    clock_gettime(CLOCK_MONOTONIC, &start);
    qsort(asc, n, sizeof(int), compare_ints);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long time_asc_ns = get_elapsed_ns(start, end);

    // Sort descending array
    clock_gettime(CLOCK_MONOTONIC, &start);
    qsort(desc, n, sizeof(int), compare_ints);
    clock_gettime(CLOCK_MONOTONIC, &end);
    long time_desc_ns = get_elapsed_ns(start, end);

    printf("Array size: %d\n", n);
    printf("  Sorted input time:    %ld ns\n", time_asc_ns);
    printf("  Reverse input time:   %ld ns\n\n", time_desc_ns);

    free(asc);
    free(desc);
}

int main() {
    run_qsort_test(4);
    run_qsort_test(1000);
    return 0;
}
