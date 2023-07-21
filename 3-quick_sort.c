#include "sort.h"

/**
 * swap_elements - Swaps two elements indice in the array.
 * @arr: The array of the swapped elements.
 * @left: left element to swap.
 * @right: right element to swap.
 */
void swap_elements(int *arr, size_t left, size_t right)
{
    int tmp;

    if (arr != NULL)
    {
        tmp = arr[left];
        arr[left] = arr[right];
        arr[right] = tmp;
    }
}

/**
 * qsrl - uses the quicksort_algorithm and Lomuto's partition to sort a sub array.
 * @arr: The sub-array to be sorted.
 * @lw: low.
 * @hh: high.
 * @se:  size(len) of the array.
 */
void qsrl(int *arr, size_t lw, size_t hh, size_t se)
{
    size_t partition_index = lw;
    int pivot;

    if ((lw >= hh) || (arr == NULL))
        return;

    pivot = arr[hh];

    while (lw < hh)
    {
        if (arr[lw] <= pivot)
        {
            if (partition_index != lw)
            {
                swap_elements(arr, partition_index, lw);
                print_array(arr, se);
            }
            partition_index++;
        }
        lw++;
    }

    if (partition_index != hh)
    {
        swap_elements(arr, partition_index, hh);
        print_array(arr, se);
    }

    if (partition_index - lw > 1)
        qsrl(arr, lw, partition_index - 1, se);

    if (hh - partition_index > 1)
        qsrl(arr, partition_index + 1, hh, se);
}

/**
 * quick_sort - uses quick sort to sort an array with Lomuto's partition .
 * @array: The array to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array != NULL)
    {
        qsrl(array, 0, size - 1, size);
    }
}
