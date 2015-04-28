/*
 * sort.h
 *
 *  Created on: 2015年4月19日
 *      Author: BK
 */

#ifndef SORT_H_
#define SORT_H_

#include <stdlib.h>

#define DATA_T double

void bubble_sort(DATA_T array[], unsigned int size);
void insert_sort(DATA_T array[], unsigned int size);
void select_sort(DATA_T array[], unsigned int size);
void quick_sort(DATA_T array[], unsigned int size);
void merge_sort(DATA_T array[], unsigned int size);

#endif /* SORT_H_ */
