#include "../inc/lab03.h"

// Simple swap function to assist the sorts, adding the swap count
void	swap(int *a, int *b, int *troca)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	if (troca != NULL)
		(*troca)++;
	// printf("swap: %d <-> %d\n", *a, *b);
}

static void	merge(int *arr,  t_pos *pos, t_count *count)
{
	int *left_side = NULL;
	int *right_side = NULL;
	int index_left = 0, index_right = 0;
	int size_left = pos->mid - pos->start + 1;
	int size_right = pos->end - pos->mid;

	// printf("merge(arr, start = %d, mid = %d, end = %d)\n", pos->start, pos->mid, pos->end);

	if (pos->start == pos->end)
		return ;

	// Create 2 Sub arrays to hold the left and right side of the array
	copy_array_pos(arr, &left_side, pos->start, pos->mid);
	copy_array_pos(arr, &right_side, pos->mid + 1, pos->end);

	// Sort the sub arrays into the original array
	int index_merged = pos->start;
	while (index_merged <= pos->end && index_left < size_left && index_right < size_right)
	{
		if (count->comp++, left_side[index_left] <= right_side[index_right])
			arr[index_merged++] = left_side[index_left++];
		else
			arr[index_merged++] = right_side[index_right++];
		count->swaps++;
	}
	
	// Copy the remaining elements of left_side, if any
	while (index_left < size_left)
		arr[index_merged++] = left_side[index_left++], count->swaps++;

	// Copy the remaining elements of right_side, if any
	while (index_right < size_right)
		arr[index_merged++] = right_side[index_right++], count->swaps++;
		
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

static int	partition(int *arr, t_pos *pos, t_count *count)
{
	int pivot = arr[pos->end];
	int i = pos->start - 1;

	for (int j = pos->start; j < pos->end; j++)
	{
		if (count->comp++, arr[j] <= pivot)
			swap(&arr[++i], &arr[j], &count->swaps);
	}
	swap(&arr[i + 1], &arr[pos->end], &count->swaps);
	return (i + 1);
}

void	quickSort(int *arr, t_pos *pos, t_count *count)
{
	if (pos->start < pos->end)
	{
		int pivot = partition(arr, pos, count);
		t_pos left = {pos->start, 0, pivot - 1};
		t_pos right = {pivot + 1, 0, pos->end};

		quickSort(arr, &left, count);
		quickSort(arr, &right, count);
	}
}