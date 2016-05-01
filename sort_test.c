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

#define ARRAY_SIZE 100000

int qsort_data[ARRAY_SIZE];
int bubble_data[ARRAY_SIZE];
int insert_data[ARRAY_SIZE];
int select_data[ARRAY_SIZE];
int quick_data[ARRAY_SIZE];
int merge_data[ARRAY_SIZE];
int heap_data[ARRAY_SIZE];

int compare(const void *a, const void *b) {
	return *((int *) a) > *((int *) b) ? 1 : -1;
}

void qsort_wrapper(int array[], int size) {
	qsort(array, size, sizeof(int), compare);
}

int check(int to_check[], int answer[], int size) {
	int i;
	for (i = 0; i < size; i++)
		if (to_check[i] != answer[i])
			return -1;

	return 0;
}

void sort_test(void (*sort)(int*, int), int* data, int* answer, int size,
		char *name) {
	clock_t start, end;

	start = clock();
	sort(data, size);
	end = clock();

	printf("%s finished, time taken: %.4fs\n", name,
			(double) (end - start) / CLOCKS_PER_SEC);

	if (check(data, answer, ARRAY_SIZE) != 0)
		printf("%s failed\n", name);

}

int main(void) {
	srand((unsigned) time(NULL));

	int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		qsort_data[i] = (int) rand() * (int) rand();
		bubble_data[i] = qsort_data[i];
		select_data[i] = qsort_data[i];
		quick_data[i] = qsort_data[i];
		merge_data[i] = qsort_data[i];
		insert_data[i] = qsort_data[i];
		heap_data[i] = qsort_data[i];
	}

	printf("data size: %d\n", ARRAY_SIZE);

	sort_test(qsort_wrapper, qsort_data, qsort_data, ARRAY_SIZE, "qsort");
	sort_test(quick_sort, quick_data, qsort_data, ARRAY_SIZE, "quick_sort");
	sort_test(heap_sort, heap_data, qsort_data, ARRAY_SIZE, "heap_sort");
	sort_test(merge_sort, merge_data, qsort_data, ARRAY_SIZE, "merge_sort");
	sort_test(insert_sort, insert_data, qsort_data, ARRAY_SIZE, "insert_sort");
	sort_test(select_sort, select_data, qsort_data, ARRAY_SIZE, "select_sort");
	sort_test(bubble_sort, bubble_data, qsort_data, ARRAY_SIZE, "bubble_sort");

	return 0;
}
