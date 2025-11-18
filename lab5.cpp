// Copyright (C) 2025 Sarvesh Kulkarni <sarvesh.kulkarni@villanova.edu>
// If you are a student in the ECE 2161 lab, you may use this code.
// Permission is NOT granted to use this code for non-educational purposes.
// Write code for bubble sort and merge sort and call the functions in main.

// WARNING! WARNING! WARNING!
//  This program declares *very* large arrays. If you have not increased your
//  stack space, expect a segmentation fault. In order to increase your
//  stack space, run the following command from your terminal:
//  ulimit -s 819200

#include <iostream>
#include <ctime>
#include "myheader.h"

using namespace std;


int main() {
	
	int		choice, sz;
	long	data[MAXSIZE], wData[MAXSIZE];
	double  begin_time, end_time, cpu_time_used;
	string  ifilename, ofilename;
	
	while (1) {

		printmenu();
		cin >> choice;
		
		switch (choice) {

			case 1: // Read input file and store data in arrays data1 and data2
                    // The function 'readfile' returns the size of the file that was read
					// If the file could not be read, 'readfile' returns -1
				
					ifilename = "lab5_test_input.txt";
					sz = readfile(ifilename, data);
			
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Input File Not Found or File cannot be opened." << endl;
						 cerr << "       Please check that the file exists, its path, and try again!" << endl << endl;
						 return 0;
					}
					else cout << endl << "File size is: " << sz << endl;
			
					break;

			case 2:

                    // First, copy the contents of the array 'data' to the working array 'wData'. Your program should sort 'wData' and not 'data'.
                    for (int i = 0; i < sz; ++i) {
                    	wData[i]= data[i];
                    }
                    
					begin_time = clock();   // start cpu timer
			
					// Call your Sort function A here to sort the array 'wData''
			        //  Note that 'wData' is of size 'sz' (see case 1).

					combsort(wData, sz);

			
					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "Comb Sort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_combsort_out.txt";
					writefile(wData, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;

			case 3:
					for (int i = 0; i < sz; ++i) {
						wData[i]= data[i];
					}
        
                    begin_time = clock();   // start timer

                    insertionSort(wData, sz); // Call Insertion Sort
        
					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "Insertion Sort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_insertionsort_out.txt";
					writefile(wData, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;

			case 4:
					for (int i = 0; i < sz; ++i) {
						wData[i]= data[i];
					}

                    begin_time = clock();   // start timer

					selectionsort(wData, sz);

					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "Selection Sort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_selectionsort_out.txt";
					writefile(wData, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;
			
			case 5:

                    // First, copy the contents of the array 'data' to the working array 'wData'. Your program should sort 'wData' and not 'data'.
					for (int i = 0; i < sz; ++i) {
						wData[i]= data[i];
					}

					begin_time = clock();   // start cpu timer
			
					// Call your Sort function D here to sort the array 'wData''
			        //  Note that 'wData' is of size 'sz' (see case 1).

					mergesort(wData, 0, sz-1);
			
					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "Merge Sort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_mergesort_out.txt";
					writefile(wData, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;
			
			case 6: // First, copy the contents of the array 'data' to the working array 'wData'. Your program should sort 'wData' and not 'data'.
			        
					for (int i = 0; i < sz; ++i) {
						wData[i]= data[i];
					}

                    begin_time = clock();   // start timer

                    quickSort(wData, 0, sz - 1); // Call Quick Sort
        
					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "Quick Sort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_quicksort_out.txt";
					writefile(wData, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;
			case 7:
					for (int i = 0; i < sz; ++i) {
						wData[i]= data[i];
					}
        
                    begin_time = clock();   // start timer
				
					shellsort(wData, sz);
				
					end_time = clock();		// end cpu timer

					cpu_time_used = (end_time - begin_time) / CLOCKS_PER_SEC;
					cout << endl << "Shell Sort ran for " << cpu_time_used << " secs.";
			
					ofilename = "lab5_shellsort_out.txt";
					writefile(wData, sz, ofilename);
					
					if (sz < 0)	 {
						 cerr << endl << "ERROR: Output File could not be opened." <<endl;
						 cerr << "       Quitting Now!" << endl << endl;
						 return 0;
					}
					else cout << endl << "Output written to " << ofilename << endl;
			
					break;
			
			case 0: // Exit Program

					cout << endl << "Received program exit command - I QUIT!" << endl << endl;

					return 0;

			default: // Error in selection

					cout << endl << "Incorrect selection, try again from the menu below." << endl;

		} // switch

	} // while
	
	return 0;
}
