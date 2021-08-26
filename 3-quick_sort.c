#include "sort.h"

/**
 * swap - swaps two ints
 * @array: array to swap
 * @first: first index
 * @second: second number to swap
 */

void swap(int *array, int first, int second)
{
	int tmp;

	tmp = array[first];
	array[first] = array[second];
	array[second] = tmp;
}

/**
 * quick_sort - sort the array from low to high
 * @array: array to sort
 * @size: size of the array
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

/**
 * sort - recursively sorts the elements low to high
 * @array: the array to sort
 * @low: point to start
 * @high: point to end
 * @size: size of the array
 */

void sort(int *array, int low, int high, size_t size)
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

/**
 * partition - parts an array at pivot index
 * @array: array to be sorted
 * @low: beginning of the comparison
 * @high: the end
 * @size: size of the array
 * Return: the index of the pivot number
 */

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
			swap(array, i, pivotIndex);
			if (pivotIndex != i)
			{
				print_array(array, size);
			}
			/* move left to right seeking value greater than pivot */
			pivotIndex++;
		}
	}
	swap(array, pivotIndex, high);
	if (pivotIndex != high)
	{
		print_array(array, size);
	}
	return (pivotIndex);
}
