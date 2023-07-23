#include "sort.h"

/**
 * swap_ints - helper function to swap two elements.
 * @a: first element to get swapped.
 * @b: The second element to get swapped.
 */
void swap_ints(int *a, int *b)
{
	int tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}

/**
 * selection_sort - Sorts an array of integers using selection sort algorithm
 * @array: array of integers to be sorted.
 * @size: size of given array.
 */
void selection_sort(int *array, size_t size)
{
	int *m;
	size_t c, _j;

	if (array == NULL || size < 2)
		return;

	for (c = 0; c < size - 1; c++)
	{
		m = array + c;
		for (_j = c + 1; _j < size; _j++)
			m = (array[_j] < *m) ? (array + _j) : m;

		if ((array + c) != m)
		{
			swap_ints(array + c, m);
			print_array(array, size);
		}
	}
}
