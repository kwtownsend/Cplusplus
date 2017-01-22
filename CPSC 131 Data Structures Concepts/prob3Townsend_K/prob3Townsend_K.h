//Kendall Townsend
//894121409


#include <iostream>


using namespace std;
//function prototype

#include "queuepk.h"

int main()
{
	queuepk <int> q;
	queuepk <int> temp;
	
	cout << "Please enter integers to be put into a linked list. Type a negative number to stop." << endl;
	int number;
	
	cin >> number;
	q.pushq(number);
		while (number >= 0)
		{
			cin >> number;
			q.pushq(number);

		}
	
	

	while(!q.Emptyq())
	{
		int x = q.popq();
		cout << x << "->";
		temp.pushq(x);
	}

	int y = temp.count();

	cout << "The number of nodes is " << y << endl;

	return 0;
}

