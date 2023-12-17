#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: an array of list to be sorted
 * @size: number of integers to be sorted
 */

void counting_sort(int *array, size_t size)
{
	int max, i;
	size_t j;
	int *counting_array, *output;

	if (array == NULL|| size < 2)
		return;
	max = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	counting_array = malloc(sizeof(int) * (max + 1));
	if (counting_array == NULL)
		return;
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (j = 0; j < size; j++)
		counting_array[array[j]]++;
	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(counting_array);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		output[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (j = 0; j < size; j++)
		array[j] = output[j];
	print_array(counting_array, max + 1);
	free(counting_array);
	free(output);
}
