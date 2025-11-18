/*
 * insertionsort.cpp
 *
 *  Created on: Nov 18, 2025
 *      Author: ece-lab-206
 */
#include "myheader.h"

void insertionSort(long data[] , int n) {
    for (int i = 1; i < n; i++) {
        long tmp = data[i];
        int j = i;
        while (j > 0 && tmp < data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }
}
