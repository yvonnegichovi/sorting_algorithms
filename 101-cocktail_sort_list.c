#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: the dl list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = *list, *end = NULL;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (swapped)
	{
		swapped = 0;
		while (temp->next != end)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		end = temp;
		while (temp->prev != NULL)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
		temp = (*list);
	}
}

/**
 * swap_nodes - swaps nodes
 * @list: double pointer to the  haed of the linked list
 * @a: the first node to be swapped
 * @b: the second node to be swapped
 */

void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == b)
		return;
	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;
	if (b->next != NULL)
		b->next->prev = a;
	else
		*list = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}
