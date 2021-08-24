#include "sort.h"


void selection_sort(int *array, size_t size)
{
            
        // search array for smallest element
        // move to first search position
        // find next smallest, repeat

    size_t tmp, x, lowIndex, element, subArray;

    if (array) 
    {
        tmp = array[0];
        lowIndex = 0;
        for (element = 0; element < size - 1; element++)
        {
            subArray = size - element;
            tmp = array[element];
            lowIndex = element;
            for (x = size - subArray; x < size - 1; x++)
            {
                // if checked value (x) is less than tmp, 
                // make it the new lowest (tmp/index)
                if (array[x] < tmp)
                {
                    tmp = array[x];
                    lowIndex = x;
                }
                
                // at end of search, swap lowindex and init value
                if (x == size - 1)
                {
                    array[lowIndex] = array[element];
                    array[element] = tmp;
                }               
            }
        }

    }
}