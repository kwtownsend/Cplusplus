//Townsend, Kendall
//894121409
//CPSC131 Section 2
//Fall 2012
//Project No.1 Part 2

#include <iostream>
#include <iomanip>
#include <cctype>
#include <fstream>
#include <string> 

using namespace std;

struct Person
{
	string name;
	int age;
	float GPA;

};

//function prototype
void Copy(string filename, Person a[]);
void Display(Person a[]);
void DisplayTeens(Person a[]);
void  AverageGpa(Person a[], float GpaAve);
void AverageAge(Person a[], float AgeAve);

//Function Name: main 
//Purpose: to gather the .txt files contents
//Return type: int
//Input parameters: none
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: Copy(), Display(), DisplayTeens(), AverageGpa(), AverageAge()
//Error messages: none

int main()
{
	Person a[5];
	float GpaAve = 0, AgeAve =0;

	Copy("data.txt", a);
	Display(a);
	DisplayTeens(a);
	AverageGpa(a, GpaAve);
	AverageAge(a, AgeAve);



}

//Function Name: Copy
//Purpose: to read from the premade .txt file
//Return type: void
//Input parameters: filename, a[]
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void Copy(string filename, Person a[])
{
	ifstream f;
	f.open("data.txt");
	for (int i=0; i<5; i++)
	{
		f >> a[i].name >> a[i].age >> a[i].GPA;
	}
	f.close();

}

//Function Name: Display
//Purpose: To display the age, gpa, and name
//Return type: void
//Input parameters: a[]
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void Display(Person a[])
{
	cout << setw(15) << left << "Name"
		<< setw(15) << left << "Age"
		<< setw(15) << left << "GPA" << endl;
	cout << setw(45) << setfill('-') << '\n' << setfill(' ') << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << endl << setw(15) << left << a[i].name
			<< setw(15) << left << a[i].age
			<< setw(15) << left << a[i].GPA;
	}


}

//Function Name: DisplayTeens
//Purpose: To determine the amount of teenagers there are.
//Return type: void
//Input parameters: a[]
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void DisplayTeens(Person a[])
{
	cout << endl << "This is the list of teenagers" << endl;
	for(int i = 0; i < 5; i++)
	{
		if(a[i].age < 20 && a[i].age > 12)
			cout << a[i].name << "	";
	}

}

//Function Name: AverageGpa
//Purpose: to find the average gpa
//Return type: void
//Input parameters: a[], GpaAve
//Output parameters: none
//User inputs: none 
//User outputs: none 
//Functions called: none
//Error messages: none

void  AverageGpa(Person a[], float GpaAve)
{
	for (int i = 0; i < 5; i++)
	{
		GpaAve += a[i].GPA;
	
	}
	GpaAve = GpaAve / 5;

	cout << endl << "The GPA average is: " << GpaAve;
}

//Function Name: AverageAge
//Purpose: To determine the average age of the people
//Return type: void
//Input parameters: a[], AgeAve
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void AverageAge(Person a[], float AgeAve)
{
	for (int i = 0; i < 5; i++)
	{
		AgeAve += a[i].age;
	
	}
	AgeAve = AgeAve / 5;

	cout << endl << "The age average is: " << AgeAve << endl;

}
