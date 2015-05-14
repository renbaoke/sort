/*
 * sort_test.c
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define ARRAY_SIZE 100000U

//#define qsort_wrapper(TYPE_T, ...) qsort(__VA_ARGS__, sizeof(TYPE_T), compare)

DATA_T qsort_data[ARRAY_SIZE];
DATA_T bubble_data[ARRAY_SIZE];
DATA_T insert_data[ARRAY_SIZE];
DATA_T select_data[ARRAY_SIZE];
DATA_T quick_data[ARRAY_SIZE];
DATA_T merge_data[ARRAY_SIZE];
DATA_T heap_data[ARRAY_SIZE];

int compare(const void *a, const void *b) {
	return *((DATA_T *) a) > *((DATA_T *) b) ? 1 : -1;
}

void qsort_wrapper(DATA_T array[], unsigned int size) {
	qsort(array, size, sizeof(DATA_T), compare);
}

int check(DATA_T to_check[], DATA_T answer[], unsigned int size) {
	unsigned int i;
	for (i = 0; i < size; i++)
		if (to_check[i] != answer[i])
			return -1;

	return 0;
}

void sort_test(void (*sort)(DATA_T*, unsigned int), DATA_T* data,
		DATA_T* answer, unsigned int size, char *name) {
	clock_t start, end;

	start = clock();
	sort(data, size);
	end = clock();

	printf("%s finished, total-time: %.4fs\n", name,
			(double) (end - start) / CLOCKS_PER_SEC);

	if (check(data, answer, ARRAY_SIZE) != 0)
		printf("%s failed\n", name);

}

int main(void) {
	srand((unsigned) time(NULL));

	unsigned int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		qsort_data[i] = (DATA_T)rand() * (DATA_T)rand();
		bubble_data[i] = qsort_data[i];
		select_data[i] = qsort_data[i];
		quick_data[i] = qsort_data[i];
		merge_data[i] = qsort_data[i];
		insert_data[i] = qsort_data[i];
		heap_data[i] = qsort_data[i];
	}

	printf("data size: %d\n\n", ARRAY_SIZE);

	sort_test(qsort_wrapper, qsort_data, qsort_data, ARRAY_SIZE, "qsort");
	sort_test(quick_sort, quick_data, qsort_data, ARRAY_SIZE, "quick_sort");
	sort_test(heap_sort, heap_data, qsort_data, ARRAY_SIZE, "heap_sort");
	sort_test(merge_sort, merge_data, qsort_data, ARRAY_SIZE, "merge_sort");
	sort_test(insert_sort, insert_data, qsort_data, ARRAY_SIZE, "insert_sort");
	sort_test(select_sort, select_data, qsort_data, ARRAY_SIZE, "select_sort");
	sort_test(bubble_sort, bubble_data, qsort_data, ARRAY_SIZE, "bubble_sort");

	return 0;
}
