#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - A function that Sorts an array of integers
 * by applying the Shell sort algorithm
 * @array: The array that's to be sorted
 * @size: The actual size of the array
 */
void shell_sort(int *array, size_t size)
{
size_t gap, x, y;
int ephem;
if (array == NULL || size < 2)
return;
for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
;
for (; gap > 0; gap /= 3)
{
for (x = gap; x < size; x++)
{
ephem = array[x];
for (y = x; y >= gap && array[y - gap] > ephem; y -= gap)
{
array[y] = array[y - gap];
}
array[y] = ephem;
}
print_array(array, size);
}
}
