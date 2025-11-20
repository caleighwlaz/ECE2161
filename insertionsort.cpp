//Jordan Barile
//ECE 2161-001
// A program to use insertion sort on both small and large arrays of numbers

#include "myheader.h"

void insertionSort(long data[] , int n) {
    for (int i = 1; i < n; i++) { //start from the second element
        long tmp = data[i]; // value to insert
        int j = i; // scan left
        while (j > 0 && tmp < data[j - 1]) { // shift elements greater than tmp to the right 
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp; // put everything in the right spot
    }
}
