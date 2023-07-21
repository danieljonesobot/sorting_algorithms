#include "sort.h"

/**
 * swap_elements - Swaps two elements in the array.
 * @arr: The array in which elements are swapped.
 * @left: The index of the first element to be swapped.
 * @right: The index of the second element to be swapped.
 */
void swap_elements(int *arr, size_t left, size_t right)
{
	int tempo;
	
	if (arr != NULL)
	{
		tempo = arr[left];
		arr[left] = arr[right];
		arr[right] = tempo;
	};
}

/**
 * qsrl - uses the quicksort with Lomuto's partition to sort a subarray.
 * @arr: The array with sub-array .
 * @lw: initial pos of the subarray.
 * @hh: last position of the subarray.
 * @se: size of the array.
 */
void qsrl(int *arr, size_t lw, size_t hh, size_t se)
{
    size_t partition_index = lw;
    size_t i;
    int pivot;

    if (lw >= hh)
        return;

    pivot = arr[hh];

    for (i = lw; i < hh; i++)
    {
        if (arr[i] <= pivot)
        {
            if (partition_index != i)
            {
                swap_elements(arr, partition_index, i);
                print_array(arr, se);
            }
            partition_index++;
        }
    }

    if (partition_index != hh)
    {
        swap_elements(arr, partition_index, hh);
        print_array(arr, se);
    }

    if (partition_index > 0)
        qsrl(arr, lw, partition_index - 1, se);

    qsrl(arr, partition_index + 1, hh, se);
}

/**
 * quick_sort - uses the quicksort Lomuto's partition .
 * @array: The array to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array != NULL && size > 1)
    {
        qsrl(array, 0, size - 1, size);
    }
}

