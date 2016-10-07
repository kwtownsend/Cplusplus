//-------------------------------------------------------------------------
//Name		Kendall Townsend
//Course	CPSC-131
//Project	No.6/Problem 1:Problem1.cpp
//Due Date	September 27, 2012
//Professor	Ahmadnia
//display linked list then delete it
//-----------------------------------------------------------------

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

	OrderedLL <int> list;

	list.insert(2);
	list.insert(5);
	list.insert(7);
	list.insert(9);
	list.insert(11);

	list.display();

	list.DeleteNode(11);
	list.DeleteNode(5);

	list.display();

	return 0;
}

//------------------------------------
//Run Results
//------------------------------------
//Today is Wed Oct 17 19:40:07 2012

//2-->5-->7-->9-->11-->NULL
//2-->7-->9-->NULL
//Press any key to continue . . .