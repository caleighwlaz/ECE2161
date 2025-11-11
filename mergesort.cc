#include "myheaders.h"

void merge(long d[], long first, long last);

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
	long mid, i1, i2, i3;
	long tmp[last-first+1];

	mid = (first + last)/2;
	i1 = 0;
	i2 = first;
	i3 = mid + 1;

	while ((i2 <= mid) && (i3 <= last)) {
		if (array[i2] < array[i3]) tmp[i1++] = array[i2++];
		else tmp[i1++] = array[i3++];
	}
	while (i2 <= mid) tmp[i1++] = array[i3++];

	for (i1 = 0; i1 < (last-first+1); ++i1) array[first+i1] = tmp[i1];

	return;
}
