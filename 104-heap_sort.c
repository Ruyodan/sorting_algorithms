#include "sort.h"

void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers array
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing binary tree
 * @size: The size of the array or tree
 * @base: The index of the base row of tree
 * @root: The root node of the binary tree
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, lg;

	left = 2 * root + 1;
	right = 2 * root + 2;
	lg = root;

	if (left < base && array[left] > array[lg])
		lg = left;
	if (right < base && array[right] > array[lg])
		lg = right;

	if (lg != root)
	{
		swap_ints(array + root, array + lg);
		print_array(array, size);
		max_heapify(array, size, base, lg);
	}
}
