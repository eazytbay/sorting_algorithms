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
size_t x = 0, y, ephem, t_low;
if (!array)
return;
while (x < (size - 1))
{
t_low = x;
y = x + 1;
while (y < size)
{
if (array[t_low] > array[y])
t_low = y;
y++;
}
if (t_lowest != x)
{
ephem = array[x];
array[x] = array[t_low];
array[t_low] = ephem;
print_array(array, size);
}
x++;
}
}
