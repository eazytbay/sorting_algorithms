#include "sort.h"

/**
 * array_parted - A function that partitions an array
 * @array: The array of integers thats to be partitioned
 * @low: the lowest position of array
 * @high: highest position of the array to be partitioned
 * @size: length of the main array
 * Return: new pivot index
 */
int array_parted(int *array, int low, int high, size_t size)
{
	int x = (low - 1);
	int pvt = array[high];
	int y, ephem;

	for (y = low; y < high; y++)
	{
		if (array[y] < pvt)
		{
			x++;
			ephem = array[y];
			array[y] = array[x];
			array[x] = ephem;
			if (x != y)
				print_array(array, size);
		}
	}

	if (array[x + 1] != array[high])
	{
		ephem = array[x + 1];
		array[x + 1] = array[high];
		array[high] = ephem;
		if ((x + 1) != y)
			print_array(array, size);
	}

	return (x + 1);
}

/**
 * fast_sort - A function that sorts an array recursively using quicksort
 * @array: array of integers
 * @low: the lowest position of array
 * @high: highest position of the array to be partitioned
 * @size: length of the main array
 * Returns: nothing
 */
void fast_sort(int *array, int low, int high, size_t size)
{
	int pvt = 0;

	if (low < high)
	{
		pvt = partition_array(array, low, high, size);
		fast_sort(array, low, pvt - 1, size);
		fast_sort(array, (pvt + 1), high, size);
	}
}

/**
 * quick_sort - A function at the base of the quicksort algorithm that
 * initializes it's implementaion
 * @array: array of integers
 * @size: length of the main array
 */
void quick_sort(int *array, size_t size)
{
	if (array || size > 1)
		fast_sort(array, 0, (size - 1), size);
}
