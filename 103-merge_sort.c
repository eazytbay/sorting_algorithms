#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * merge_sort - A function that Sorts an array of integers
 * and arranges them in ascending order using the merge sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
int *temp = malloc(size * sizeof(int));
if (array == NULL || size < 2)
return;
if (temp == NULL)
return;
merge_sort_recursive(array, temp, 0, size - 1);
free(temp);
}
/**
 * merge_sort_recursive - A function that recursively divides the array and
 * merges the sorted halves
 * @array: The array to be sorted
 * @temp: The temporary array for merging
 * @start: The start of the index
 * @end: The End of the index
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
if (start < end)
{
size_t mid = start + (end - start) / 2;
merge_sort_recursive(array, temp, start, mid);
merge_sort_recursive(array, temp, mid + 1, end);
merge(array, start, mid, end);
}
}
/**
 * merge -A function that Merges two halves of an array into a sorted whole
 * @array: The array to be sorted
 * @start: The Start of the index
 * @mid: The Middle of the index
 * @end: The End of the index
 */
void merge(int *array, size_t start, size_t mid, size_t end)
{
size_t x, y, z;
size_t n1 = mid - start + 1;
size_t n2 = end - mid;
int *left = malloc(n1 * sizeof(int));
int *right = malloc(n2 * sizeof(int));
for (x = 0; x < n1; x++)
left[x] = array[start + x];
for (y = 0; y < n2; y++)
right[y] = array[mid + 1 + y];
x = 0;
y = 0;
z = start;
while (x < n1 && y < n2)
{
if (left[x] <= right[y])
{
array[z] = left[x];
x++;
}
else
{
array[z] = right[y];
y++;
}
z++;
}
while (x < n1)
{
array[z] = left[x];
x++;
z++;
}
while (y < n2)
{
array[z] = right[y];
y++;
z++;
}
free(left);
free(right);
}
