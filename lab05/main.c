#include "lab05.h"

static int compareInt(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

static double time_algorithm(int *vector, int vectorSize, int n, int (*search)(int *, int, int))
{
	clock_t	end;
	clock_t	start;

	srand(0);
	
	start = clock();

	for (int i = 0; i < n; i++)
		search(vector, vectorSize, rand());

	end = clock();

	return (double)(end - start) / CLOCKS_PER_SEC * 1000.0; // Convert to milliseconds
}

static void populate_vectors(int *vector, int *hashTable, int n, int tableSize)
{
	for (int i = 0; i < tableSize; i++)
		hashTable[i] = NOT_FOUND;

	srand(0);
	for (int i = 0; i < n; i++)
		vector[i] = rand();

	srand(0);
	for (int i = 0; i < n; i++)
		insertHash(hashTable, tableSize, rand());
}

int main()
{
	int ns[] = {1000, 10000, 50000, 100000};
	int numTests = sizeof(ns) / sizeof(ns[0]);
	int n = 0;
	t_algos algos = {NULL, NULL, 0, {0.0, 0.0}};

	
	for (int t = 0; t < numTests; t++)
	{
		n = ns[t];
		algos.hashTableSize = n * LOAD_FACTOR;
		algos.vector		= (int *)malloc(n * sizeof(int));
		algos.hashTable 	= (int *)malloc(algos.hashTableSize * sizeof(int));
		if (!algos.vector || !algos.hashTable)
		{
			fprintf(stderr, "Memory allocation failed\n");
			return EXIT_FAILURE;
		}

		// Populate vectors and sort them
		populate_vectors(algos.vector, algos.hashTable, n, algos.hashTableSize);
		qsort(algos.vector, n, sizeof(int), compareInt);

		// Get search times for search algorithms
		algos.searchsTime[0] = time_algorithm(algos.vector, n, n, binarySearch);
		algos.searchsTime[1] = time_algorithm(algos.hashTable, algos.hashTableSize, n, searchHash);

		printf("N = %d:\n"
				GREEN "\t🟩 Vetor ordenado = %.3f ms\n" RESET
				CYAN "\t🔷 Hash table \t  = %.3f ms" RESET "\n",
				n, algos.searchsTime[0], algos.searchsTime[1]);

		free(algos.vector);
		algos.vector = NULL;
		free(algos.hashTable);
		algos.hashTable = NULL;
	}

	return 0;
}
