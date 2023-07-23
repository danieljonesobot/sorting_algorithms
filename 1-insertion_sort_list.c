#include "sort.h"

/**
 * swap_nodes - this function swaps two nodes
 * @h: This pointer points to the head of a node
 * @n1: this points to the first node
 * @n2: this is the node to be swapped with.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - function to sort doubly linked list
 * @list: this points to the head of a doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter_a, *inst, *tempo;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter_a = (*list)->next; iter_a != NULL; iter_a = tempo)
	{
		tempo = iter_a->next;
		inst = iter_a->prev;
		while (inst != NULL && iter_a->n < inst->n)
		{
			swap_nodes(list, &inst, iter_a);
			print_list((const listint_t *)*list);
		}
	}
}
