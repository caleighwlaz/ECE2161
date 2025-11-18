// DO NOT forget to add the prototypes for your ASort, BSort, and other functions below!

#include <iostream>
#include <fstream>
#define MAXSIZE	 2100000
#include "myheader.h"

using namespace std;

void	printmenu() {

			cout << endl;
			cout << "Please choose from the following menu:" << endl;
			cout << "  1: Read input file" << endl;
			cout << "  2: Sort using combsort" << endl;
			cout << "  3: Sort using insertionsort" << endl;
			cout << "  4: Sort using selectionsort" << endl;
			cout << "  5: Sort using mergesort" << endl;
			cout << "  6: Sort using quicksort" << endl;
			cout << "  7: Sort using shellsort" << endl;
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
