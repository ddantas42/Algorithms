#include "lab05.h"

static int compareInt(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int main()
{
	int ns[] = {1000, 10000, 50000, 100000};
	int numTests = sizeof(ns) / sizeof(ns[0]);
	int *vector = NULL;
	int *hashTable = NULL;
	int tableSize = 0;
	int n = 0;

	
	for (int t = 0; t < numTests; t++)
	{
		n = ns[t];
		*vector = (int *)malloc(n * sizeof(int));
		*hashTable = (int *)malloc((n * LOAD_FACTOR) * sizeof(int));
		tableSize = n * LOAD_FACTOR;

		for (int i = 0; i < tableSize; i++)
			hashTable[i] = NOT_FOUND;

		srand(0);
		for (int i = 0; i < n; i++)
		{
			int value = rand();
			vector[i] = value;
			insertHash(hashTable, tableSize, value);
		}

		qsort(vector, n, sizeof(int), compareInt);

		srand(0);

		clock_t start = clock();
		for (int i = 0; i < n; i++)
		{
			int value = rand();
			binarySearch(vector, n, value);
		}
		clock_t end = clock();
		double timeVector = (double)(end - start) / CLOCKS_PER_SEC;

		srand(0);
		start = clock();
		for (int i = 0; i < n; i++)
		{
			int value = rand();
			searchHash(hashTable, tableSize, value);
		}
		end = clock();
		double timeHash = (double)(end - start) / CLOCKS_PER_SEC;

		printf("n = %d: Vetor ordenado = %.6f s | Hash table = %.6f s\n",
			 n, timeVector, timeHash);

		free(vector);
		free(hashTable);
	}

	return 0;
}
