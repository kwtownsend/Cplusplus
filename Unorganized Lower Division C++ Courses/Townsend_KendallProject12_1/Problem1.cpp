//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.12/Problem 1:Problem1.cpp
//Due Date	December 6, 2012
//Professor	Ahmadnia
//
//Take two fractions and overload all functions and use them
//--------------------------------------------------------------------------

#include <iostream>
#include "POINT.h"

#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t b;
	time(&b);
	cout << "Today is " << ctime(&b) << endl;

	POINT A, B, C;
	cout << "Enter a fraction: ";
	A.ReadPoint();
	cout << endl << "Enter another fraction: ";
	B.ReadPoint();
	cout << endl;
	//addition
	C = A + B;
	A.ShowPoint(); cout << " + "; B.ShowPoint();
	cout << " = "; C.ShowPoint();
	//subtraction
	C = A - B;
	cout << endl;
	A.ShowPoint(); cout << " - "; B.ShowPoint();
	cout << " = "; C.ShowPoint();
	//multiplication
	C = A * B;
	cout << endl;
	A.ShowPoint(); cout << " * "; B.ShowPoint();
	cout << " = "; C.ShowPoint();
	//division
	C = A / B;
	cout << endl;
	A.ShowPoint(); cout << " / "; B.ShowPoint();
	cout << " = "; C.ShowPoint();
	//++
	cout << endl;
	A.ShowPoint();
	cout << "++ = ";
	C = A++;
	C.ShowPoint();
	//--
	cout << endl;
	B.ShowPoint();
	cout << "-- = ";
	C = B--;
	C.ShowPoint();
	cout << endl;

	return 0;
}


//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Dec 05 16:47:24 2012

//Enter a fraction: 4/5

//Enter another fraction: 6/7

//(4/5) + (6/7) = (58/35)
//(4/5) - (6/7) = (-2/35)
//(4/5) * (6/7) = (24/35)
//(4/5) / (6/7) = (28/30)
//(4/5)++ = (5/6)
//(6/7)-- = (5/6)
//Press any key to continue . . .