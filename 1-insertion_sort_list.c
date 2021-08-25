#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	/* create current node */
	listint_t *current = NULL, *tmp = NULL, *lastNode = NULL;

	if (list == NULL)
		return;
	
	current = (*list)->next;
	tmp = current;
	while (current != NULL)
	{
		current = current->next;
		/* if you aren't at the head and the value of n is greater than prev value*/
		if (tmp->n < tmp->prev->n)
		{
			while(tmp->prev != NULL && tmp->n < tmp->prev->n)
			{
				lastNode = tmp->prev;
				lastNode->next = tmp->next;
				/* if in the middle */
							/* account for the end  */
				if (lastNode->prev != NULL)
				{
					lastNode->prev->next = tmp;
				}

				if (tmp->next != NULL)
				{
					tmp->next->prev = lastNode;
				}
				
				/*swap*/
				tmp->prev = lastNode->prev;

				tmp->next = lastNode;

				lastNode->prev = tmp;

				if (tmp->prev == NULL)
				{
					(*list) = tmp;
				}
			}
		}
		tmp = current;
		print_list(*list);

	}
}