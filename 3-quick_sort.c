#include "sort.h"
/**
 * make a pivot, so its position to the left is smaller
 * and the position to the right is greater
 * quick sort left, quick sort right.
 * 
 * element at array[j] <= pivot index, true i++, swap(arr[i], arr[j]), print
 * 
 */

void quick_sort(int *array, size_t size)
{
	/* null check*/
	/* sort from lowest to highest */
	sort(array, 0, size - 1, size)
}

void sort(int* array, int low, int high, size_t size)
{
	int pivotIndex;
	if (low < high)
	{
		/* find the index of the pivot*/
		pivotIndex = partition(array, low, high, size);
		/* apply quicksort for left and right*/
		sort(array, low, pivotIndex - 1, size);
		sort(array, pivotIndex + 1, high, size);
	}
}

int partition(int *array, int low, int high, size_t size)
{
	int pivotIndex = low;
	int pivot = array[high];
	int i;
	/* move all the lowest to the left and all the greater to right*/

	for (i = low; i < high; i++)
	{
		/* if the current element <= pivot, i++, swap*/
		if (array[i] <= pivot)
		{
			/*swap*/
			pivotIndex++;
		}
	}
	/*
}