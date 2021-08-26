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
	/* null check */
	if (array)
	{
		/* sort from lowest to highest, recursively */
		sort(array, 0, size - 1, size)
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
		sort(array, low, pivotIndex, size);
		sort(array, pivotIndex + 1, high, size);
	}
}

int partition(int *array, int low, int high, size_t size)
{	
	int pivotIndex = high;
	int i, j, tmp;
	/* move all the lowest to the left and all the greater to right*/
	while (i < j)
	{
		while (array[i] <= pivot)
		{
			/* move left to right seeking value greater than pivot */
			i++;
		}
		while (array[j] >= pivot)
		{
			/* move right to left seeking value less than pivot */
			j++;
		}
		if (i < j)
		{
			/* if i has not passed j, swap found values */
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	/* swap pivot with last found higher value */
	tmp = array[pivotIndex];
	array[pivotIndex] = array[i];
	array[i] = tmp;
	if (i != pivotIndex)
	{
		print_array(array, size);
	}
}