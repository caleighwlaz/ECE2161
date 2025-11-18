/*
 * selectionsort.cpp
 *
 *  Created on: Nov 18, 2025
 *      Author: ece-lab-206
 */
#include "myheader.h"

void swap_sel(long &a, long &b) {
	long t = a; //creates temporary variable in order to swap values
	a = b; //puts second value into first variable
	b = t; //puts first value into second variable
}
void selectionsort(long data[], int n) {
	for(int i = 0, j, least; i < n-1; i++) {
		for(j = i+1, least = i; j < n; j++) {
			if(data[j] < data[least]) {
				least = j;
			}
		}
		swap_sel(data[least], data[i]);
	}
}


