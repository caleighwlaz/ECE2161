#include <string>
#include <unistd.h>

#define MAXSIZE	 2100000

using namespace std;

void	printmenu(); //prints options to user
void	printarray(long data[], long size);  //prints data array
int		readfile(string infilename, long d[]); //reads input file
int		writefile(long data[], long size, string outfilename); //writes outout file

void	swap(long& x, long& y); //swaps two variable values

void combsort(long data[], const int n);  //sorts wData using Comb Sort

void insertionSort(long data[], int n);  //sorts wData using Insertion Sort

void swap_sel(long &a, long &b); //another swap function that swaps two variable values

void selectionsort(long data[], int n); //sorts wData using Selection Sort
void mergesort(long data[], long first, long last); //sorts wData using Merge Sort
void merge(long array[], long first, long last); //used for Merge Sort
void quickSort(long data[], long left, long right);  //sorts wData using Quick Sort
void shellsort(long data[], int n); //sorts wData using Shell Sort
