//Townsend, Kendall
//894121409
//CPSC131 Section 2
//Fall 2011
//Project No.1 Part 1B

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;

//function prototype
void FindEvenIntegers(int a[]);
void FindOddIntegers(int a[]);

//Function Name: main
//Purpose: to create an array of 15 numbers 20-40, and sort them by even and odd
//Return type: int
//Input parameters: none 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: FindEvenIntegers(), FindOddIntegers()
//Error messages: none

int main()
{
	int a[15] = {20 ,31, 23, 22, 37, 39, 40, 25, 28, 29, 33, 32, 24, 26, 21};

	FindEvenIntegers(a);
	FindOddIntegers(a);
}

//Function Name: FindEvenIntegers
//Purpose: to sort the array by even numbers
//Return type: void
//Input parameters: a[] 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void FindEvenIntegers(int a[])
{
	cout << "Even integers in array a: ";

	for( int i = 0; i < 15; i++)
	{
		if(a[i] % 2 == 0)
			cout << a[i] << " ";
	}

}

//Function Name: FindOddIntegers
//Purpose: to determine which numbers are odd
//Return type: void
//Input parameters: a[] 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void FindOddIntegers(int a[])
{
	cout << endl << "Odd integers in array a: ";

	for( int i = 0; i< 15; i++)
	{
		if(a[i] % 2 != 0)
			cout << a[i] << " ";
	}

}
