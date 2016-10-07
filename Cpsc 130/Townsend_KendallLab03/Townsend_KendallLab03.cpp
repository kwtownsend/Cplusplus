//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallHW01.cpp
//Credits:

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>

using namespace std;

//Function Name: main()
//Purpose:To Find your pay after taxes and the value of all the taxes
//Return type: int, double, bool, string
//Input parameters: double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, double name 
//Output parameters:double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, double name
//User inputs: name, pay, whether to repeat
//User outputs: fedTax, stateTax, netPay, ssTax, medicareTax
//Functions called:
//Error messages: won't compile not sure what to do



int main(bool again)
{
	do
	{
		double GeneratePaySlip();
	}
	while (!again);

	return 0;
}

bool HaveMoreEmployee()
{
	bool valid;
	char moreEmployee;
	bool again;
		do
	{
		cout << "Do you have another employee? (Y/N)" << endl;
		cin >> fixed >> moreEmployee;
		moreEmployee = toupper(moreEmployee);
		
		if (moreEmployee != 'Y' || moreEmployee != 'N')
		{
			cout << "Invalid Answer" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	if (moreEmployee == 'Y')
		again = true;
	else
		again = false;

	return again;
	}

double GeneratePaySlip()
{
	double GetEmployeeInfo();
	double ComputePay();
	double Print();
	bool done;
	return done;
}

double Print(double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, double name)
{
	//setting up time
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	//formatting
		cout << setw(16) << left << "NIMRODSPACE.COM"
			<< setw(34) << right << "Earnings Statement" << endl;
		cout << setw(50) << left << "11111 Big-Talon Chicken Road" << endl;
		cout << setw(50) << left << "Fullerton, CA 92821" << endl;
		cout << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
		cout << left << setw(10) << "Date/Time: " 
			<< right << setw(40) << asctime(timeinfo);
		cout << setw(10) << left << "Employee: "
			<< setw(40) << name << endl;
		cout << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		cout << setw(10) << left << "Earnings "
			<< setw(30) << right << "$"
			<< setw(10) << right << pay << endl;
		cout << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		cout << setw(50) << left << "Deductions Statutory" << endl;
		cout << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "Federal Income Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << fedTax << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "Social Security Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << ssTax << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "Medicare Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << medicareTax << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "CA State Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << stateTax << endl;
		cout << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		cout << setw(30) << right << "NET PAY"
			<< setw(10) << right << "$"
			<< setw(10) << netPay;
		bool ok;
		return ok;

}

double GetEmployeeInfo()
{
	string GetEmployeeName();
	double GetEmployeePay();

	bool info;
	return info;
}

double ComputePay(double fedTax, double stateTax, double ssTax, double medicareTax, double pay)
{
	double ComputeFedTax();
	double ComputeStateTax();
	double ComputeSSTax();
	double ComputeMedicareTax();

	double netPay;

	netPay = pay - (fedTax - stateTax - ssTax - medicareTax);

	return netPay;
}


string GetEmployeeName()
{
	string name;
	bool valid;

	//Get employee name
	do
	{
		cout << "What is the Employees Name?" << endl;
		cin >> name;
		if (name == "")
		{
			cout << "Invalid Name" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	return name;
}




double GetEmployeePay()
{
	double pay;
	bool valid;
	//Gather gross pay
	do
	{
		cout << "What is your Gross Pay?" << endl;
		cin >> pay;
		if (pay == 0)
		{
			cout << "Invalid Pay" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	
	return pay;
}


double ComputeFedTax(double pay)
{
	double fedTax;
	fedTax = pay * 0.15;

	return fedTax;
}

double ComputeStateTax(double pay)
{
	double stateTax;
	stateTax = pay * 0.035;

	return stateTax;
}

double ComputeSSTax(double pay)
{
	double ssTax;
	ssTax = pay * 0.0575;
	
	return ssTax;
}

double ComputeMedicareTax(double pay)
{
	double medicareTax;
	medicareTax = pay * 0.0275;
	
	return medicareTax;
}