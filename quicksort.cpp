// Jordan Barile
// Lab 5, ECE 2161-001
// A program to use quick sort in order to sort both short and long arrays of numbers

#include "myheader.h"

void quickSort(long data[], long left, long right) {
    if (left >= right) //base case
        return;

    long bound = data[(left + right) / 2]; //pivot is the middle element

    long i = left, j = right;
    while (i <= j) {
        while (data[i] < bound) i++; //move i forwards until a number greater than i is found
        while (data[j] > bound) j--; //move j backwards until a number less than j is found

        if (i <= j) { // if i and j dont cross, swap them and keep going
            swap(data[i], data[j]);
            i++;
            j--;
        }
    }

    if (left < j) //sort the left
        quickSort(data, left, j);
    if (i < right) //sort the right
        quickSort(data, i, right);
}
