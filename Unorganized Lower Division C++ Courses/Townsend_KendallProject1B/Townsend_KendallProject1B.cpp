//Townsend, Kendall
//894121409
//CPSC131 Section 2
//Fall 2012
//Project No.1 Part 1C

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>

using namespace std;

//function prototype
void DisplayDays(char Days[][15]);
void NewDisplay(char Days[][15]);

//Function Name: main
//Purpose: to test members of <cstring>
//Return type: int
//Input parameters: none
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: DisplayDays(), NewDisplay()
//Error messages: none

int main()
{
	char Days[7][15] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
	DisplayDays(Days);
	NewDisplay(Days);
}

//Function Name: Displaydays
//Purpose: to display the 2d array of days, and length.
//Return type: void
//Input parameters: days[][]
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void DisplayDays(char Days[][15])
{
	for(int i = 0; i < 7; i++)
	{
		cout << Days[i] << '\t' << strlen(Days[i]) << endl;
	}
}

//Function Name: NewDisplay
//Purpose: to change "Saturday" into "Sat" and make all of them uppercase.
//Return type: void
//Input parameters: days[][]
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void NewDisplay(char Days[][15])
{
	strcpy(Days[6], "Sat");
	for(int i =0; i< 7; i++)
	{
		strupr(Days[i]);
		cout << Days[i] << " ";			
	}

}