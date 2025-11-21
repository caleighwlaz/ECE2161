// Caleigh Wlazlowski
// ECE 2161-001
// This program uses Selection Sort to sort a dataset.

#include "myheader.h"

void swap_sel(long &a, long &b) {
	long t = a; //creates temporary variable in order to swap values
	a = b; //puts second value into first variable
	b = t; //puts first value into second variable
}
void selectionsort(long data[], int n) {
	for(int i = 0, j, least; i < n-1; i++) {
		for(j = i+1, least = i; j < n; j++) {		//gets two values from dataset
			if(data[j] < data[least]) {				//compares which of the two variables is smaller
				least = j;							//replaces the smaller value
			}
		}
		swap_sel(data[least], data[i]);				//swaps least value into the output dataset
	}
}


