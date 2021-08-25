#include "sort.h"

void selection_sort(int *array, size_t size)
{
    size_t x, lowIndex, element, subArray;
    int tmp;

    if (array) 
    {
        tmp = array[0];
        lowIndex = 0;
        for (element = 0; array[element + 1] != NULL; element++)
        {
            subArray = size - element;
            tmp = array[element];
            lowIndex = element;
            
            for (x = size - subArray; x < size; x++)
            { 
                /** if checked value (x) is less than tmp, **/
                /** make it the new lowest (tmp/index) **/
                if ((size_t) array[x] < tmp)
                {
                    tmp = array[x];
                    lowIndex = x;
                }
                /** at end of search, swap lowindex and init value **/
                if (x == size - 1)
                {
                    array[lowIndex] = array[element];
                    array[element] = tmp;
                }
            }
            
            print_array(array, size);
        }
    }
}
