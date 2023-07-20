#include "sort.h"

/**
 * bubble_sort - the bubble sort function for bubble sorting
 * @array: the array
 * @size: len of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int sort = 0, temp;
	size_t i;

	while(sort == 0)
	{
		sort = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i + 1];
				array[i+1] = array[i];
				array[i] = temp;
				sort = 0;
				print_array(array, size);
			}
		}
	}
}
