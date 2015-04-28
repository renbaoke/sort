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

#define qsort_wrapper(TYPE_T, ...) qsort(__VA_ARGS__, sizeof(TYPE_T), compare)

DATA_T qsort_data[ARRAY_SIZE];
DATA_T bubble_data[ARRAY_SIZE];
DATA_T insert_data[ARRAY_SIZE];
DATA_T select_data[ARRAY_SIZE];
DATA_T quick_data[ARRAY_SIZE];
DATA_T merge_data[ARRAY_SIZE];

int compare(const void *a, const void *b) {
	return *((DATA_T *) a) > *((DATA_T *) b) ? 1 : -1;
}

int check(DATA_T to_check[], DATA_T answer[], unsigned int size) {
	unsigned int i;
	for (i = 0; i < size; i++)
		if (to_check[i] != answer[i])
			return -1;

	return 0;
}

int main(void) {
	clock_t start, end;

	unsigned int i;
	for (i = 0; i < ARRAY_SIZE; i++) {
		qsort_data[i] = (DATA_T) rand();
		bubble_data[i] = qsort_data[i];
		select_data[i] = bubble_data[i];
		quick_data[i] = select_data[i];
		merge_data[i] = quick_data[i];
		insert_data[i] = merge_data[i];
	}

	start = clock();
	qsort_wrapper(DATA_T, qsort_data, ARRAY_SIZE);
	end = clock();
	printf("qsort finished, total-time:\t\t%.4fs\n",
			(double) (end - start) / CLOCKS_PER_SEC);

	start = clock();
	quick_sort(quick_data, ARRAY_SIZE);
	end = clock();
	printf("quick_sort finished, total-time:\t%.4fs\n",
			(double) (end - start) / CLOCKS_PER_SEC);
	if (check(quick_data, qsort_data, ARRAY_SIZE) != 0)
		printf("quick_sort failed\n");

	start = clock();
	merge_sort(merge_data, ARRAY_SIZE);
	end = clock();
	printf("merge_sort finished, total-time:\t%.4fs\n",
			(double) (end - start) / CLOCKS_PER_SEC);
	if (check(merge_data, qsort_data, ARRAY_SIZE) != 0)
		printf("merge_sort failed\n");

	start = clock();
	insert_sort(insert_data, ARRAY_SIZE);
	end = clock();
	printf("insert_sort finished, total-time:\t%.4fs\n",
			(double) (end - start) / CLOCKS_PER_SEC);
	if (check(insert_data, qsort_data, ARRAY_SIZE) != 0)
		printf("insert_sort failed\n");

	start = clock();
	select_sort(select_data, ARRAY_SIZE);
	end = clock();
	printf("select_sort finished, total-time:\t%.4fs\n",
			(double) (end - start) / CLOCKS_PER_SEC);
	if (check(select_data, qsort_data, ARRAY_SIZE) != 0)
		printf("select_sort failed\n");

	start = clock();
	bubble_sort(bubble_data, ARRAY_SIZE);
	end = clock();
	printf("bubble_sort finished, total-time:\t%.4fs\n",
			(double) (end - start) / CLOCKS_PER_SEC);
	if (check(bubble_data, qsort_data, ARRAY_SIZE) != 0)
		printf("bubble_sort failed\n");

	return 0;
}
