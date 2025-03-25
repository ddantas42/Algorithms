#include "lab01.h"

/**
 * Grupo 8
 * Diogo Gonçalves,	nº 13869
 * Miguel Pereira,	nº 13909
 * Maxim Antipeco,	nº 13893
 * David Gonçalves,	nº 13897
 */

/** 
 * Find the index of a value in an integer array using sequencial search
 * @param arr	Array to search the index
 * @param n 	The size of the array
 * @param elem	The value we are searching for in the array
 * @returns 	The index of the array where elem is or -1 if it isn't 
 */
int procura_sequencial(int arr[], int n, int elem)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == elem)
			return i;
	}
	return -1;
}

/** 
 * Find the index of a value in an integer array using binary search
 * @param arr	Array to search the index
 * @param n 	The size of the array
 * @param elem  The value we are searching for in the array
 * @returns 	The index of the array where elem is or -1 if it isn't 
 */
int procura_binaria(int arr[], int n, int elem)
{
	int start = 0;
	int finish = n;
	int mid = n / 2;
	int last_mid = -1;

	while (last_mid != mid)
	{
		if (arr[mid] == elem)
			return mid;
		else if (arr[mid] < elem)
			start = mid;
		else if (arr[mid] > elem)
			finish = mid;
		last_mid = mid;
		mid = ((start + finish) / 2);
	}
	return -1;
}

/**
 * Find the index of a value in an integer array using jump search
 * @param arr	Array to search the index
 * @param n 	The size of the array
 * @param elem  The value we are searching for in the array
 * @returns 	The index of the array where elem is or -1 if it isn't 
 */
static int jump_search(int arr[], int n, int elem)
{
	const int jump = sqrt(n);
	int start = 0;
	int next = jump;

	// Jump foward until the element is smaller than the next element
	while (start < n && arr[next - 1] < elem)
	{
		start = next;
		next += jump;
		if (next >= n)
			next = n;
	}

	// Sequencial search after the jump
	for (int i = start; i < next; i++)
	{
		if (arr[i] == elem)
			return i;
	}

	return -1;
}

int main(int argc, char *argv[])
{
	int size = 0;
	int elem = 0;
	int *arr = NULL;

	arr = init_array(argc, argv, &size);

	// Selecting element to search
	printf("Select an element to search: ");
	scanf("%d", &elem);

	// Sequencial Search
	printf("\n---- Sequencial Search ----\n");
	run_algorithm(arr, size, elem, &procura_sequencial);

	// Binary Search
	printf("\n---- Binary Search ----\n");
	if (is_sorted(arr, size) == 0)
		printf("Array is not sorted, no binary search\n");
	else
		run_algorithm(arr, size, elem, &procura_binaria);

	// Jump Search
	printf("\n---- Jump Search ----\n");
	if (is_sorted(arr, size) == 0)
		printf("Array is not sorted, no jump search\n");
	else
		run_algorithm(arr, size, elem, &jump_search);

	free(arr);

	return 0;	

}