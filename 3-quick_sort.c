#include "sort.h"


void swap(int *array, int first, int second)
{
	int tmp;
	tmp = array[first];

	array[first] = array[second];
	array[second] = tmp;
}

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
	/* null check */
	if (array)
	{
		/* sort from lowest to highest, recursively */
		sort(array, 0, size - 1, size);
	}
}

void sort(int* array, int low, int high, size_t size)
{
	int pivotIndex;
	/* check for at least 2 values */
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
	/*j = pivotIndex - 1;*/
	/* move all the lowest to the left and all the greater to right*/
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			swap (array, i, pivotIndex);
			if (pivotIndex != i)
			{
				print_array(array, size);
			}
			/* move left to right seeking value greater than pivot */
			pivotIndex++;
		}
		if (array[i] => pivot)
		{			
			swap (array, pivotIndex, high);
			if (pivotIndex != i)
			{
				print_array(array, size);
			}
			/* move left to right seeking value greater than pivot */
		}
	}
	/* swap pivot with last found higher value */
/*	if (i != pivotIndex)
	{
		print_array(array, size);
	}*/
	return (pivotIndex);
}
