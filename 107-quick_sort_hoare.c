#include "sort.h"

void swap_ints(int *a, int *b);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
int hoare_partition(int *array, size_t size, int left, int right);


/**
 * hoare_partition - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int bwl, pivot, abv;

	pivot = array[right];
	for (abv = left - 1, blw = right + 1; abv < blw;)
	{
		do {
			abv++;
		} while (array[abv] < pivot);
		do {
			blw--;
		} while (array[blw] > pivot);

		if (abv < blw)
		{
			swap_ints(array + abv, array + blw);
			print_array(array, size);
		}
	}

	return (abv);
}

/**
 * swap_ints - Swap two integers in an array.
* @b: The second integer
 * @a: The first integer 
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * quick_sort_hoare - Sort an array of integers in ascending
* @size: The size of the array.
 * @array: An array of integers.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion
* @size: The size of the array.
 * @left: The starting index of the array partition to order
 * @array: An array of integers to sort.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, prt - 1);
		hoare_sort(array, size, prt, right);
	}
}
