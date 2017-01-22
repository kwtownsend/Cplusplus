//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab10.cpp
//Credits:

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

struct Student
{
	int id;
	string name;
	double score;
};

//function proto
void GetInfo(Student students[], int size);
void GetStudentInfo(Student& s);
int GetMaxScore(Student students[], int size);
void GetID(int& id);
void GetName(string& name);
void GetScore(double& score);
void PrintAll(Student students[], int size);
void GetSize(int& size);

int main()
{
	int size;
	GetSize(size);

	Student *students = 0;
	students = new Student [size];

	GetInfo(students, size);
	int maxIndex = GetMaxScore(students, size);
	PrintMaxScore(students, maxIndex);
	PrintAll(students, size);


}

void PrintMaxScore(Student students[], int index)
{
	cout << "The Maximum score is " << students[index].score << " by " << students[index].name << endl;
}

void GetSize(int& size)
{
	cout << "Please enter the number of Students: ";

	bool valid;

		do
	{
		cin >> size;
		if(cin.fail())
		{
			cout << "Invalid Size" << endl;
			cin.clear();
			valid = false;
		}

		else if (size < 1)
		{
			cout << "Invalid Size" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);

}

void GetInfo(Student students[], int size)
{
	for(int i = 0; i < size; i++)
	{
		GetStudentInfo(students[i]);
	}

}

void GetStudentInfo(Student& s)
{
	
	GetID(s.id);
	GetName(s.name);
	GetScore(s.score);

}

void GetName(string& name)
{
	cout << "Student Name: ";
	bool valid;
	do
	{
		getline(cin, name);
		if(name == "")
		{
			cout << "Invalid Name";
			valid = false;
		}
		else
			valid = true;
	}while(!valid);

}
void GetID(int& id)
{
	cout << "Student ID: ";
	bool valid;
		do
	{
		cin >> id;
		if(cin.fail())
		{
			cout << "Invalid ID Number" << endl;
			cin.clear();
			valid = false;
		}

		else if (id < 1)
		{
			cout << "Invalid ID Number" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);
}

void GetScore(double& score)
{
	cout << "Students Score: ";
	bool valid;
		do
	{
		cin >> score;
		if(cin.fail())
		{
			cout << "Invalid Score" << endl;
			cin.clear();
			valid = false;
		}

		else if (score < 1 || score > 100)
		{
			cout << "Invalid Score" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
		cin.ignore(1000, '\n');
	}while(!valid);
}

int GetMaxScore(Student students[], int size)
{
	
	int maxIndex = 0;

	for(int i=1; i < size; i++)
	{
		if(students[i].score >  students[maxIndex].score)
		{
			maxIndex = i;
		}
	}

	return maxIndex;
}

void PrintAll(Student students[], int size)
{
	for(int i=0; i < size; i++)
	{

		cout << "Student " << students[i].name << " with ID " << students[i].id << " recieved a score of " << students[i].score << endl;

	}


}