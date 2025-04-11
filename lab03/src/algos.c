#include "../inc/lab03.h"

// Simple swap function to assist the sorts, adding the swap count
void	swap(int *a, int *b, int *troca)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	if (troca != NULL)
		(*troca)++;
	printf("swap: %d <-> %d\n", *a, *b);
}

static void DumpArray(int *dest, int *arr, int int start, int end)
{
	for (int i = start; i <= end; i++)
		dest[i] = arr[i];
}

static void	merge(int *arr,  t_pos *pos, t_count *count)
{
	int *left_side = NULL;
	int *right_side = NULL;
	int index_left, index_right;
	int size_left = pos->mid - pos->start + 1;
	int size_right = pos->end - pos->mid;

	printf("merge(arr, start = %d, mid = %d, end = %d)\n", pos->start, pos->mid, pos->end);

	if (pos->start == pos->end)
		return ;

	// Create 2 Sub arrays
	print_array(arr, SIZE);
	copy_array_pos(arr, &left_side, pos->start, pos->mid);
	copy_array_pos(arr, &right_side, pos->mid + 1, pos->end);
	printf("Left: "), print_array(left_side, size_left);
	printf("Right: "), print_array(right_side, size_right);

	index_left = 0;
	index_right = 0;
	for (int index_merged = pos->start; \
		index_merged < pos->end && \
		index_left < size_left && \
		index_right < size_right; index_merged++)
	{
		if (left_side[index_left] <= right_side[index_right])
			swap(&arr[index_merged], &left_side[index_left++], &count->swaps);
		else
			swap(&arr[index_merged], &right_side[index_right++], &count->swaps);
	}
	printf("After merge "), print_array(arr, SIZE);
	printf("Left: "), print_array(left_side, size_left);
	printf("Right: "),print_array(right_side, size_right);
	// Free the memory allocated for the sub arrays
	free(left_side);
	free(right_side);
}

/**
 * Will sort the array using MergeSort
 * @param arr  The array to sort
 * @param pos  The position of the array to sort (start, mid, end)
 * @param count  The count of comparisons and swaps (comp, swap)
 */
void		mergeSort(int *arr, t_pos *pos, t_count *count)
{
	pos->mid = pos->start + (pos->end - pos->start) / 2;

	t_pos	left = {pos->start, 0, pos->mid};
	t_pos	right = {pos->mid + 1, 0, pos->end};
	
	if (pos->start < pos->end)
	{
		mergeSort(arr, &left, count);
		mergeSort(arr, &right, count);
		merge(arr, pos, count);
	}
}


