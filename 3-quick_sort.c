#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * lomuto_partition - partitions an array using
 * the lamunto partition scheme
 * @array: the array to be partitioned
 * @low: the index of the low element of the partition
 * @high: the index of the high element of the partition
 * @size: number of elements in the array
 * Return: the index of the pivot element after partitioning
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * swap - swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * quicksort_recursive - recursively sorts a partition of an array using
 * the Quick sort algorithm, specifically lomunto technique
 * @array: the array to be sorted
 * @low: the index of the low element of the partition
 * @high: the index of the high element of the partition
 * @size: number of elements in the array
 */

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be sorted
 * @size: the number of elements in the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
