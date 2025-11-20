// Julianna Petrelli
// Lab #5, ECE 2161-001
// The following code preforms a comb sort algorithm on a given data set. 
#include "myheader.h"

void combsort(long data[], const int n) {                //function declaration and definition
	int step = n, j, k;
	while ((step = int(step/1.3)) > 1)                   //phase 1
		for (j = n - 1; j >= step; j--) {                //processes data from right to left, sorting larger numbers first
			k = j - step;
			if (data[j] < data[k])
				swap(data[j], data[k]);                  //swaps numbers if element j is less than element k, so that element j appears first
		}
	bool again = true;
	for (int i = 0; i < n - 1 && again; i++) {           //phase 2
		for (j = n - 1, again = false; j > i; --j) {
			if (data[j] < data[j-1]) {
				swap(data[j], data[j-1]);
				again = true;                            //adds a flag to discontinue processing after no swaps were performed (data has been sorted)
			}
		}
	}
}
