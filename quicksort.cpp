/*
 * quicksort.cpp
 *
 *  Created on: Nov 18, 2025
 *      Author: ece-lab-206
 */

#include "myheader.h"

void quickSort(long data[], long left, long right) {
    if (left >= right)
        return;

    long bound = data[(left + right) / 2];

    long i = left, j = right;
    while (i <= j) {
        while (data[i] < bound) i++;
        while (data[j] > bound) j--;

        if (i <= j) {
            swap(data[i], data[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(data, left, j);
    if (i < right)
        quickSort(data, i, right);
}
