#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: pointer to a pointer to the head  of the dl list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current  = (*list)->next;
	while (current != NULL)

	{
		temp = current;
		prev = current->prev;
		while (prev != NULL && prev->n > temp->n)
		{
			if (temp->next != NULL)
				temp->next->prev = prev;
			if (prev->prev != NULL)
				prev->prev->next = temp;
			else
				*list = temp;
			temp->prev = prev->prev;
			prev->next = temp->next;
			temp->next = prev;
			prev->prev = temp;
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
