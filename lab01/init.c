#include "lab01.h"

/** 
 * Gets an input from stdin and returns the integer value
 * @returns 	The size of the array 
 */
int get_array_size()
{
	int size = 0;
	printf("Lengh of the array (> 1): ");
	scanf("%d", &size);
	if (size < 1)
	{
		printf("Size has to be bigger than 1");
		exit(1);
	}
	return size;
}

/** 
 * Declares the array dinamicly using stdin (no arguments provided to the program)
 * @param size 	Size of the array
 * @returns 	The size of the array 
 */
int *declare_manual_array(int size)
{
	int *arr = (int *)calloc(sizeof(int), size);
	if (arr == NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}

	printf("Introduce the numbers of the array:\n");
	for(int i = 0; i < size; i++)
	{
		// printf("arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}

	// print array
	// printf("Array: ");
	// for (int i = 0; i < size; i++)
	// 	printf("%d ", arr[i]);
	// printf("\n");

	return arr;
}

/** 
 * Declares the array dinamicly using argv
 * @param size 	Size of the array
 * @param argv 	Array of strings to convert to integers
 * @returns 	The size of the array 
 */
int *declare_automatic_array(int size, char *argv[])
{
	int *arr = (int *)calloc(sizeof(int), size);
	if (arr == NULL)
	{
		printf("Memory allocation failed");
		exit(1);
	}

	for (int i = 0; i < size; i++)
		arr[i] = atoi(argv[i + 1]);

	// print array
	printf("Size: %d\nArray: ", size);
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	return arr;
}

int *init_array(int argc, char *argv[], int *size)
{
	int *arr = NULL;

	if (argc > 1)
	{
		printf("Arguments detected: using arguments as array\n");
		*size = argc - 1;
		if (*size < 1)
		{
			printf("Not enough arguments\n");
			exit(1);
		}
		arr = declare_automatic_array(*size, argv);
	}
	else
	{
		printf("No arguments detected: using stdin as array\n");
		*size = get_array_size();
		arr = declare_manual_array(*size);
	}

	return arr;
}