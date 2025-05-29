#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOAD_FACTOR 2
#define NOT_FOUND -1

// Função de hash simples
int hash(int key, int size)
{
	return key % size;
}

// Estrutura da tabela de hash com tratamento de colisão por endereçamento aberto linear
void insertHash(int *hashTable, int size, int key)
{
	int index = hash(key, size);
	
	while (hashTable[index] != NOT_FOUND)
		index = (index + 1) % size;
		
	hashTable[index] = key;
}

int searchHash(int *hashTable, int size, int key)
{
	int index = hash(key, size);
	int start = index;

	while (hashTable[index] != NOT_FOUND)
	{
		if (hashTable[index] == key)
			return index;
		index = (index + 1) % size;
		if (index == start)
			break;
	}
	return NOT_FOUND;
}

// Função de comparação para qsort
int compareInt(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

// Busca binária
int binarySearch(int *arr, int n, int key)
{
	int low = 0, high = n - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return NOT_FOUND;
}

int main() {
	int ns[] = {1000, 10000, 50000, 100000};
	int numTests = sizeof(ns) / sizeof(ns[0]);

	for (int t = 0; t < numTests; t++)
	{
		int n = ns[t];
		int *vector = (int *)malloc(n * sizeof(int));
		int *hashTable = (int *)malloc((n * LOAD_FACTOR) * sizeof(int));
		int tableSize = n * LOAD_FACTOR;

		// Inicializa hash table
		for (int i = 0; i < tableSize; i++)
			hashTable[i] = NOT_FOUND;

		// Geração dos valores e inserção
		srand(0);
		for (int i = 0; i < n; i++)
		{
			int value = rand();
			vector[i] = value;
			insertHash(hashTable, tableSize, value);
		}

		// Ordena o vetor
		qsort(vector, n, sizeof(int), compareInt);

		// Segunda geração para busca (os mesmos valores com mesma semente)
		srand(0);

		// Busca binária
		clock_t start = clock();
		for (int i = 0; i < n; i++)
		{
			int value = rand();
			binarySearch(vector, n, value);
		}
		clock_t end = clock();
		double timeVector = (double)(end - start) / CLOCKS_PER_SEC;

		// Busca na tabela de dispersão
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
