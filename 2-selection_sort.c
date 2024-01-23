#include "sort.h"

/**
 * selection_sort -A function that sorts an array using selection sorting
 * algorithm
 * @array: This is an array of integers
 * @size: length of the array
 * Return: Absolutely nothing
 */
void selection_sort(int *array, size_t size)
{
size_t x, y, ephem, t_low;
if (!array)
return;
for (x = 0; x < (size - 1); x++)
{
t_low = x;
for (y = x + 1; y < size; y++)
{
if (array[t_low] > array[y])
t_low = y;
}
if (t_low != x)
{
ephem = array[x];
array[x] = array[t_low];
array[t_low] = ephem;
print_array(array, size);
}
}
}
