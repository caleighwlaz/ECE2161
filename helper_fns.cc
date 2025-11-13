// DO NOT forget to add the prototypes for your ASort, BSort, and other functions below!

#include <iostream>
#include <ostream>
#include <string>
#include <unistd.h>
#define MAXSIZE	 2100000
#include "myheader.h"

using namespace std;

void	printmenu() {

			cout << endl;
			cout << "Please choose from the following menu:" << endl;
			cout << "  1: Read input file" << endl;
			cout << "  2: Sort using Asort" << endl;
			cout << "  3: Sort using Bsort" << endl;
			cout << "  4: Sort using Csort" << endl;
			cout << "  5: Sort using Dsort" << endl;
			cout << "  6: Sort using Esort" << endl;
			cout << "  7: Sort using Fsort" << endl;
			cout << "  0: Exit program" << endl;
			cout << endl << "Enter your choice: ";

		return;

}
void	printarray(long data[], long size) {

			cout << endl << "Array contents:" << endl;
			for (int i = 0; i < size; ++i)	  cout << data[i] << " ";
			cout << endl;

		return;

}
int		readfile(string infilename, long d[]) {

			long		i, size;
			ifstream	infile;

			// IMP NOTE: In the C++ std before C++11, the constructor for an
			//           ifstream or ofstream object takes a const char*, not
			//           a string. In compilers that follow the C++11 std or
			//			 later, we may write instead: infile.open(infilename);

			infile.open(infilename.c_str());

			if (!infile.is_open()) { size = -1;}
			else {
				for (i = 0; (!infile.eof()) && (i < MAXSIZE); ++i) {
					infile >> d[i];
				} // for

				size = i-1; // eof() causes an extra (invalid) number to be read
				infile.close();
			} // else

			return size;
}

int		writefile(long data[], long size, string outfilename) {

			long		i, errcode;
			ofstream	outfile;

			// IMP NOTE: In the C++ std before C++11, the constructor for an
			//           ifstream or ofstream object takes a const char*, not
			//           a string. In compilers that follow the C++11 std or
			//			 later, we may write instead: outfile.open(outfilename);
			outfile.open(outfilename.c_str());

			if (!outfile.is_open()) { errcode = -1;}
			else {
				for (i = 0; i < size; ++i)	  outfile << data[i] << " ";

				errcode = 0;
				outfile.close();
			} // else

			return errcode;
}

void	swap(long& x, long& y) {

			long	tmp;

			tmp = x;
			x = y;
			y = tmp;

			return;
}

void combsort(long data[], const int n) {
	int step = n, j, k;
	while ((step = int(step/1.3)) > 1)                   //phase 1
		for (j = n - 1; j >= step; j--) {
			k = j - step;
			if (data[j] < data[k])
				swap(data[j], data[k]);
		}
	bool again = true;
	for (int i = 0; i < n - 1 && again; i++) {           //phase 2
		for (j = n - 1, again = false; j > i; --j) {
			if (data[j] < data[j-1]) {
				swap(data[j], data[j-1]);
				again = true;
			}
		}
	}
}

void insertionSort(long data[], size_t n) {
    for (size_t i = 1; i < n; i++) {
        long tmp = data[i];
        size_t j = i;
        while (j > 0 && tmp < data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }
}

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
