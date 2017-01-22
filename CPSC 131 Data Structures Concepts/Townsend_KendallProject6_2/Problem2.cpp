//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.6/Problem 2:Problem2.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//
//Combine two linked list
//--------------------------------------------------------------------------

#include <iostream>
#include "OrderedLL.h"
#include <ctime>

using namespace std;

//function prototype

int main()
{
	//print the current time
	time_t a;
	time(&a);
	cout << "Today is " << ctime(&a) << endl;

	OrderedLL <int> A;
	OrderedLL <int> B;
	OrderedLL <int> AUB;

	A.insert(2);
	A.insert(5);
	A.insert(7);
	A.insert(8);
	A.insert(9);

	B.insert(2);
	B.insert(4);
	B.insert(5);
	B.insert(7);
	B.insert(8);
	B.insert(9);
	B.insert(11);

	CombineNode(A, B, AUB);

	A.display();
	B.display();
	AUB.display();

	return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 17 19:43:31 2012

//2-->5-->7-->8-->9-->NULL
//2-->4-->5-->7-->8-->9-->11-->NULL
//2-->4-->5-->7-->8-->9-->NULL
//Press any key to continue . . .