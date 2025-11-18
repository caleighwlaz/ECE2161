#include <string>
#include <unistd.h>

#define MAXSIZE	 2100000

using namespace std;

void	printmenu();
void	printarray(long data[], long size);
int		readfile(string infilename, long d[]);
int		writefile(long data[], long size, string outfilename);

void	swap(long& x, long& y);

void combsort(long data[], const int n);

void insertionSort(long data[], int n);

void swap_sel(long &a, long &b);

void selectionsort(long data[], int n);
void mergesort(long data[], long first, long last);
void merge(long array[], long first, long last);
void quickSort(long data[], long left, long right);
void shellsort(long data[], int n);
