/*
 * sort.c
 *
 * Copyright 2015 BK <renbaoke@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */

#include "sort.h"

void bubble_sort(DATA_T array[], unsigned int size) {
	DATA_T temp;
	unsigned i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
}

void insert_sort(DATA_T array[], unsigned int size) {
	DATA_T temp;
	unsigned i, j, k;
	for (i = 1; i < size; i++) {
		temp = array[i];

		for (j = 0; j < i; j++)
			if (array[j] > temp)
				break;

		for (k = i; k > j; k--)
			array[k] = array[k - 1];

		array[j] = temp;
	}
}

void select_sort(DATA_T array[], unsigned int size) {
	DATA_T temp;
	unsigned int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = i + 1; j < size; j++)
			if (array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
}

static int partition(DATA_T array[], unsigned int low, unsigned int high) {
	DATA_T pivot = array[low];

	while (low < high) {
		while (low < high && array[high] >= pivot)
			high--;
		if (low < high)
			array[low++] = array[high];
		while (low < high && array[low] <= pivot)
			low++;
		if (low < high)
			array[high--] = array[low];
	}

	array[low] = pivot;

	return low;
}

static void _quick_sort(DATA_T array[], unsigned int low, unsigned int high) {
	DATA_T pivot;
	if (low < high) {
		pivot = partition(array, low, high);
		_quick_sort(array, low, pivot);
		_quick_sort(array, pivot + 1, high);
	}
}

void quick_sort(DATA_T array[], unsigned int size) {
	_quick_sort(array, 0, size - 1);
}

static void merge(DATA_T array[], unsigned int low, unsigned int middle,
		unsigned int high) {
	unsigned int first = low;
	unsigned int second = middle + 1;
	DATA_T *temp = (DATA_T *) malloc((high - low + 1) * sizeof(DATA_T));

	unsigned int i = 0;
	while (first <= middle && second <= high)
		temp[i++] =
				array[first] < array[second] ? array[first++] : array[second++];

	if (first > middle)
		while (second <= high)
			temp[i++] = array[second++];
	else if (second > high)
		while (first <= middle)
			temp[i++] = array[first++];

	i = 0;
	while (low <= high)
		array[low++] = temp[i++];

	free(temp);
}

static void _merge_sort(DATA_T array[], unsigned int low, unsigned int high) {
	unsigned int middle;
	if (low < high) {
		middle = (low + high) / 2;
		_merge_sort(array, low, middle);
		_merge_sort(array, middle + 1, high);
		merge(array, low, middle, high);
	}
}

void merge_sort(DATA_T array[], unsigned int size) {
	_merge_sort(array, 0, size - 1);
}
