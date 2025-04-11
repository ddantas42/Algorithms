#include "../inc/lab03.h"

// Simple swap function to assist the sorts, adding the swap count
void	swap(int *a, int *b, int *troca)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	if (troca != NULL)
		(*troca)++;
}

static void	merge(int *arr,  t_pos *pos, t_count *count)
{
	int *copy_left = NULL;
	int *copy_right = NULL;
	int index_left, index_right;
	int size_left = pos->mid - pos->start + 1;
	int size_right = pos->end - pos->mid;
	int biggest_size;

	printf("merge(arr, start = %d, mid = %d, end = %d)\n", pos->start, pos->mid, pos->end);

	if (pos->start == pos->end)
		return ;

	// Create 2 Sub arrays
	print_array(arr);
	copy_array_pos(arr, &copy_left, pos->start, pos->mid);
	copy_array_pos(arr, &copy_right, pos->mid + 1, pos->end);
	printf("Left: "), print_array(copy_left);
	printf("Right: "), print_array(copy_right);

	index_left = 0;
	index_right = 0;
	for (int index_merged = pos->start; index_merged < pos->end; index_merged++)
	{
		if (count->comp++, size_right != index_right && size_left != index_left && copy_right[index_right] >= copy_left[index_left])
			arr[index_merged] = copy_left[index_left++];
		else
			arr[index_merged] = copy_right[index_right++];
	}

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


