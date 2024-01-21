#include "sort.h"

/**
 * bubble_sort - A function that sorts an array
 * of integers in an ascending order.
 *
 * @array: data to be sorted.
 * @size: size of array.
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t in = 0, ephem = 0, increm;

	if (array == NULL || size < 2)
	{
		return;
	}

	increm = 1;
	while (increm < size)
	{
		in = 0;
		while (in < size - 1)
		{
			if (array[in] > array[in + 1])
			{
				ephem = array[in];
				array[in] = array[in + 1];
				array[in + 1] = ephem;

				print_array(array, size);
			}
			in++;
		}
		increm++;
	}
}
