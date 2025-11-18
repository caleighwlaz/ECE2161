/*
 * shellsort.cpp
 *
 *  Created on: Nov 18, 2025
 *      Author: ece-lab-206
 */

void shellsort(long data[], int n) {
	int i, j, h_count, h;
	int increments[20], k;
	//create an appropriate number of increments h
	for(h = 1, i = 0; h < n; i++) {
		increments[i] = h;
		h = 3*h + 1;
	}
	//loop on the number of different increments h
	for(i--; i >= 0; i--) {
		h = increments[i];
		//loop on the number of subarrays h-sorted in ith pass
		for(h_count = h; h_count < 2*h; h_count++) {
			//insertionm sort for subarray containing every hth element
			for(j = h_count; j < n; ) {
				long tmp = data[j];
				k = j;
				while(k-h >= 0 && tmp < data[k-h]) {
					data[k] = data[k-h];
					k -= h;
				}
				data[k] = tmp;
				j += h;
			}
		}
	}
}
