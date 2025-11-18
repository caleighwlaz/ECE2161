/*
 * mergesort.cpp
 *
 *  Created on: Nov 18, 2025
 *      Author: ece-lab-206
 */

void merge(long array[], long first, long last);

void mergesort(long data[], long first, long last) {
	if (first < last) {
		long mid = (first + last)/2;
		mergesort(data, first, mid);
		mergesort(data, mid+1, last);
		merge(data, first, last);
	}
	return;
}
void merge(long array[], long first, long last) {
	long mid, i1, i2;

	mid = (first + last)/2;
	i1 = first;
	i2 = mid + 1;

	int k = first;

	int n1 = i2 - i1;
	int n2 = last - mid;



	long head[n1];
	long tail[n2];

	for (int i = 0; i < n1; i++) {
		head[i] = array[first + i];
	}
	for (int j = 0; j < n2; j++) {
		tail[j] = array[mid + 1 + j];
	}

	int i = 0;
	int j = 0;

	while (i < n1 && j < n2) {
		if (head[i] <= tail[j]) {
			array[k] = head[i];
			i++;
		}
		else {
			array[k] = tail[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		array[k] = head[i];
		i++;
		k++;
	}
	while (j < n2) {
			array[k] = tail[j];
			j++;
			k++;
		}

	return;
}
