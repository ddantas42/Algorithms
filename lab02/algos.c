#include "lab02.h"

// Simple swap function to assist the sorts, adding the swap count
void	swap(int *a, int *b, int *troca)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	if (troca != NULL)
		(*troca)++;
}

/**
 * Bubble sort with go through the array n times, comparing each element with the next one.
 * If the next element is smaller than the current one, they are swapped.
 * This process is repeated n times, until the array is sorted.
 * O(n^2)
 * @param arr[] - array to be sorted
 * @param n - size of the array
 * @param troca - number of swaps
 * @param comp - number of comparisons
 */
void	bubble_sort(int arr[], int n, int *troca, int *comp)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if ((*comp)++, arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1], troca);
				print_array(arr);
			}
		}
	}
}

/**
 * Bubble sort with go through the array n times, comparing each element with the next one.
 * If the next element is smaller than the current one, they are swapped.
 * This process is repeated n times, until the array is sorted.
 * This version of the algorithm will stop if no swaps are made in a pass, as the array is already sorted.
 * O(n^2)
 * @param arr[] - array to be sorted
 * @param n - size of the array
 * @param troca - number of swaps
 * @param comp - number of comparisons
 */
void	bubble_sort_opt(int arr[], int n, int *troca, int *comp)
{
	int swapped = 0;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = 0;
		for (int j = 0; j < n - i - 1; j++)
		{
			if ((*comp)++, arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1], troca);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}

/**
 * Bubble sort with go through the array n times, comparing each element with the next one.
 * If the next element is smaller than the current one, they are swapped.
 * This process is repeated n times, until the array is sorted.
 * This version of the algorithm will stop if no swaps are made in a pass, as the array is already sorted.
 * It will also start the comparisons from the first element that efetuaded a swap before
 * O(n^2)
 * @param arr[] - array to be sorted
 * @param n - size of the array
 * @param troca - number of swaps
 * @param comp - number of comparisons
 */
void	bubble_sort_opt_v2(int arr[], int n, int *troca, int *comp)
{
	int swapped = 0;
	int first = 0;
	int min_index = 0;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = 0;
		first = 0;
		for (int j = min_index; j < n - i - 1; j++)
		{
			if ((*comp)++, arr[j] > arr[j + 1])
			{
				if (first == 0)
				{
					first = 1;
					min_index = j - 1;
				}
				swap(&arr[j], &arr[j + 1], troca);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
	}
}

/**
 * Selection sort will go through the array n times, selecting the smallest element
 * and swapping it with the first element of the array.
 * This process is repeated n times, until the array is sorted.
 * O(n^2)
 * @param arr[] - array to be sorted
 * @param n - size of the array
 * @param troca - number of swaps
 * @param comp - number of comparisons
 */
void	selection_sort(int arr[], int n, int *troca, int *comp)
{
	int min_index = 0;

	for (int i = 0; i < n - 2; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n - 1; j++)
		{
			if ((*comp)++, arr[j] < arr[min_index])
				min_index = j;
		}
		if (min_index != i)
			swap(&arr[min_index], &arr[i], troca);
	}
}

/**
 * Selection sort will go through the array n times, selecting the smallest element
 * and swapping it with the first element of the array.
 * This process is repeated n times, until the array is sorted.
 * This version is trying to fix the above algorithm, since for random arrays it does not sort them
 * O(n^2)
 * @param arr[] - array to be sorted
 * @param n - size of the array
 * @param troca - number of swaps
 * @param comp - number of comparisons
 */
void	selection_sort_v2(int arr[], int n, int *troca, int *comp)
{
	int min_index = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;
		for (int j = i + 1; j < n; j++)
		{
			if ((*comp)++, arr[j] < arr[min_index])
				min_index = j;
		}
		if (min_index != i)
			swap(&arr[min_index], &arr[i], troca);
	}
}

/**
 * Insertion sort will go through the array n times, selecting the next element
 * and comparing it with the previous elements.
 * If the next element is smaller than the current one, they are swapped.
 * This process is repeated n times, until the array is sorted.
 * O(n^2)
 * @param arr[] - array to be sorted
 * @param n - size of the array
 * @param troca - number of swaps
 * @param comp - number of comparisons
 */
void	insertion_sort(int arr[], int n, int *troca, int *comp)
{
	int j = 1;
	for (int i = 1; i < n; i++)
	{
		j = i;
		while (j > 0 && (*comp)++, arr[j] < arr[j - 1])
		{
			swap(&arr[j], &arr[j - 1], troca);
			j--;
		}
	}
}
