//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.h
//Credits: Nathan Niyomtham

#pragma once
#include <string>

using namespace std;

#define MAX 3

class Student
{
public:
	Student(void);
	string GetFirstname();
	void SetFirstName(string first);
	string GetFirstName();
	void SetLastName(string last);
	string GetLastName();
	void InitScores();
	void SetScore(double score, int i);
	string Fullname() const;
	double Total() const;
	double Average() const;

private:
	string firstname;
	string lastname;
	double scores[MAX];
};

