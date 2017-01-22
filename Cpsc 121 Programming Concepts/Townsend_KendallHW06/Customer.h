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
public:
	friend ostream& operator << (ostream& out, const Customer& obj);
	friend istream& operator >> (istream& in, Customer& obj);
	string GetFirstname();
	void SetFirstName(string first);
	string GetFirstName();
	void SetLastName(string last);
	int GetID();
	void SetID(int id);
	double GetBalance();
	double Balance() const;
	void SetBalance(double bal);
	string GetLastName();
	string Fullname() const;
	void InitBalances();
	void SetID(double id, int i);
	int ID() const;
	void SearchID() const;
	bool operator==(const Customer& obj);
	bool operator<(const Customer& obj);
	bool operator>(const Customer& obj);
	bool operator>=(const Customer& obj);
	bool operator<=(const Customer& obj);

private:
	int ids;
	string firstname;
	string lastname;
	double balance;

};

