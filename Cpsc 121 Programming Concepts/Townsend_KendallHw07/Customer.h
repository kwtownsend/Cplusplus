//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Student.h
//Credits: Nathan Niyomtham

#pragma once
#include <string>

using namespace std;

#define MAX 50

class Customer
{
	friend ostream& operator << (ostream& out, const Customer& obj);
	friend istream& operator >> (istream& in, Customer& obj);
public:
	Customer(void);
	void SetFirstName(string first);
	string GetFirstName() const;
	void SetLastName(string last);
	int GetID() const;
	void SetID(int id);
	double GetBalance() const;
	void SetBalance(double bal);
	string GetLastName() const;
	string GetFullName() const;
	void SetFullName(string firstname, string lastname);
	void InitBalances();
	void SetID(double id, int i);
	bool operator==(const Customer& obj);
	bool operator<(const Customer& obj);
	bool operator>(const Customer& obj);
	bool operator>=(const Customer& obj);
	bool operator<=(const Customer& obj);
	void Print() const;
	~Customer(void);

private:
	int ids;
	string firstname;
	string lastname;
	string fullname;
	double balance;

};

