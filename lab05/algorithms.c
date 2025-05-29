#include "lab05.h"

int hash(int key, int size)
{
	return key % size;
}

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