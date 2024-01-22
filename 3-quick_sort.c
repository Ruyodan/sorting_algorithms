#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Partition the array around the pivot.
 * @array: The array to partition.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot = array[high];
    size_t i = (low - 1);

    for (size_t j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap_ints(&array[i], &array[j]);
            if (array[i] != array[j])
                print_array(array, size);
        }
    }
    swap_ints(&array[i + 1], &array[high]);
    if (array[i + 1] != array[high])
        print_array(array, size);

   	 return (i + 1);
}

/**
 * lomuto_sort - Sort an array of integers in ascending order using the Quick sort algorithm.
 * @array: The array to sort.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void lomuto_sort(int *array, size_t low, size_t high, size_t size)
{
	    if (low < high)
    {
        	size_t pi = lomuto_partition(array, low, high, size);

        	lomuto_sort(array, low, pi - 1, size);
        	lomuto_sort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using the Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
    	if (array == NULL || size < 2)
	return;

	lomuto_sort(array, 0, size - 1, size);
}

