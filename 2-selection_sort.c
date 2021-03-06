#include "sort.h"


/**
 * selection_sort - sort substrings of decreasing size based on lowest element
 * @array: elements to be sorted
 * @size: length of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t x, lowIndex, element, subArray;
	int tmp;

	if (array && size > 2)
	{
		tmp = array[0];
		lowIndex = 0;
		for (element = 0; element < (size - 2); element++)
		{
			subArray = size - element;
			tmp = array[element];
			lowIndex = element;
			for (x = size - subArray; x < size; x++)
			{
				if (array[x] < tmp)
				{
					tmp = array[x];
					lowIndex = x;
				}
				if (x == size - 1)
				{
					array[lowIndex] = array[element];
					array[element] = tmp;
				}
			}
			if (lowIndex != element)
				print_array(array, size);
		}
	}
	else if (array && size == 2)
	{
		if (array[1] < array[0])
		{
			tmp = array[0];
			array[0] = array[1];
			array[1] = tmp;
			print_array(array, size);
		}
	}
}
