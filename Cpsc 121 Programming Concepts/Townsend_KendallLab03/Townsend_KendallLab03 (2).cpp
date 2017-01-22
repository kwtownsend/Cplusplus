//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallLab03.cpp
//Credits: Lisa

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

//function prototypes-----------------------------------------------------------------------
bool HaveMoreEmployee();
void GeneratePaySlip();
void Print(double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, string name);
void GetEmployeeInfo(string& name, double& pay);
double ComputePay(double& fedTax, double& stateTax, double& ssTax, double& medicareTax, double& pay);
string GetEmployeeName();
double GetEmployeePay();
double ComputeFedTax(double pay);
double ComputeStateTax(double pay);
double ComputeSSTax(double pay);
double ComputeMedicareTax(double pay);
void PrintPayFile(double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, string name);



//Function Name: main()
//Purpose:To generate a pay slip and ask if you have more employees
//Return type: int
//Input parameters: none
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: GeneratePaySlip(); HaveMoreEmployee();
//Error messages: none


int main()
{ 

	do
	{
		GeneratePaySlip();
	}
	while (HaveMoreEmployee());

	return 0;
}

//Function Name: HaveMoreEmployee()
//Purpose: To check and see if you have more employees
//Return type: bool
//Input parameters: none
//Output parameters: none
//User inputs: again
//User outputs: none
//Functions called: none
//Error messages: none

// function definitions -----------------------------------------
bool HaveMoreEmployee()
{
	bool valid;
	char moreEmployee;
	bool again;

	do
	{
		cout << endl << "Do you have another employee? (Y/N)" << endl;
		cin >> moreEmployee;

		cin.ignore(); // prevents getline from taking left over characters

		moreEmployee = toupper(moreEmployee);
		
		if (moreEmployee != 'Y' && moreEmployee != 'N')
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


//Function Name: GeneratePaySlip()
//Purpose: To generate pay a pay slip using all the other functions
//Return type: void
//Input parameters: none
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: GetEmployeeInfo( name,  pay), ComputePay( fedTax,  stateTax,  ssTax,  medicareTax,  pay), Print(fedTax, stateTax, ssTax, medicareTax, pay, netPay, name), PrintPayFile(fedTax, stateTax, ssTax, medicareTax, pay, netPay, name);
//Error messages:

void GeneratePaySlip()
{
	string name;
	double pay, fedTax,stateTax, ssTax, medicareTax, netPay;
	GetEmployeeInfo( name,  pay);
	netPay = ComputePay( fedTax,  stateTax,  ssTax,  medicareTax,  pay);
	Print(fedTax, stateTax, ssTax, medicareTax, pay, netPay, name);
	PrintPayFile(fedTax, stateTax, ssTax, medicareTax, pay, netPay, name);
}


//Function Name: Print()
//Purpose: To print the pay slip
//Return type: void
//Input parameters: double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, string name
//Output parameters: none
//User inputs: none
//User outputs: fedTax, stateTax, ssTax, medicareTax, pay, netPay, name
//Functions called: none
//Error messages: none

void Print(double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, string name)
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
			<< setw(10) << right << -fedTax << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "Social Security Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -ssTax << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "Medicare Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -medicareTax << endl;
		cout << setw(12) << "" 
			<< setw(26) << left << "CA State Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -stateTax << endl;
		cout << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		cout << setw(30) << right << "NET PAY"
			<< setw(10) << right << "$"
			<< setw(10) << netPay;


		
}

//Function Name: GetEmployeeInfo()
//Purpose: to call upon functions, and get the pay, and name of the employee
//Return type: void
//Input parameters: string& name, double& pay
//Output parameters: none
//User inputs: none
//User outputs: fedTax, stateTax, ssTax, medicareTax, pay, netPay, name
//Functions called: GetEmployeeName(); GetEmployeePay();
//Error messages: none

void GetEmployeeInfo(string& name, double& pay)
{
	name = GetEmployeeName();
	pay = GetEmployeePay();


}

//Function Name: ComputePay()
//Purpose: To get all the tax amounts, and calculate the netpay
//Return type: double
//Input parameters: double& fedTax, double& stateTax, double& ssTax, double& medicareTax, double& pay
//Output parameters: netPay
//User inputs: none
//User outputs: netPay
//Functions called: ComputeFedTax(pay); ComputeStateTax(pay); ComputeSSTax(pay); ComputeMedicareTax(pay);
//Error messages: none

double ComputePay(double& fedTax, double& stateTax, double& ssTax, double& medicareTax, double& pay)
{
	fedTax = ComputeFedTax(pay);
	stateTax = ComputeStateTax(pay);
	ssTax = ComputeSSTax(pay);
	medicareTax = ComputeMedicareTax(pay);

	double netPay;

	netPay = pay - (fedTax - stateTax - ssTax - medicareTax);

	return netPay;
}


//Function Name: GetEmployeeName()
//Purpose: To get the employees name
//Return type: string
//Input parameters: none
//Output parameters: name
//User inputs:  name
//User outputs: none
//Functions called: none
//Error messages: none

string GetEmployeeName()
{
	string name;
	bool valid;

	//Get employee name
	do
	{
		cout << "What is the Employees Name?" << endl;
		getline(cin,name);
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


//Function Name: GetEmployeePay()
//Purpose: to get the employees pay
//Return type: double
//Input parameters: none
//Output parameters: pay
//User inputs:  pay
//User outputs: none
//Functions called: none
//Error messages: none

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

//Function Name: ComputeFedTax()
//Purpose: to compute the federal tax
//Return type: double
//Input parameters: double pay
//Output parameters: fedTax
//User inputs: none
//User outputs: valid
//Functions called: none
//Error messages: none

double ComputeFedTax(double pay)
{
	double fedTax;
	fedTax = pay * 0.15;

	return fedTax;
}

//Function Name: ComputeStateTax()
//Purpose: to compute the state tax
//Return type: double
//Input parameters: double pay
//Output parameters: stateTax
//User inputs: none
//User outputs: valid
//Functions called: none
//Error messages: none

double ComputeStateTax(double pay)
{
	double stateTax;
	stateTax = pay * 0.035;

	return stateTax;
}

//Function Name: ComputeSSTax()
//Purpose: to compute the social security tax
//Return type: double
//Input parameters: double pay
//Output parameters: ssTax
//User inputs: none
//User outputs: valid
//Functions called: none
//Error messages: none

double ComputeSSTax(double pay)
{
	double ssTax;
	ssTax = pay * 0.0575;
	
	return ssTax;
}

//Function Name: ComputeMedicareTax()
//Purpose: to compute the medicare tax
//Return type: double
//Input parameters: double pay
//Output parameters: stateTax
//User inputs: none
//User outputs: valid
//Functions called: none
//Error messages: none

double ComputeMedicareTax(double pay)
{
	double medicareTax;
	medicareTax = pay * 0.0275;
	
	return medicareTax;
}

//Function Name: PrintPayFile()
//Purpose: To print the pay slip into a .txt file
//Return type: void
//Input parameters: double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, string name
//Output parameters: none
//User inputs: none
//User outputs: fedTax, stateTax, ssTax, medicareTax, pay, netPay, name
//Functions called: none
//Error messages: none

void PrintPayFile(double fedTax, double stateTax, double ssTax, double medicareTax, double pay, double netPay, string name)
{
	ofstream outfile;
	string filename = name + "'s Pay Slip.txt";
	outfile.open(filename);
	
	//setting up time
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	//formatting
		outfile << setw(16) << left << "NIMRODSPACE.COM"
			<< setw(34) << right << "Earnings Statement" << endl;
		outfile << setw(50) << left << "11111 Big-Talon Chicken Road" << endl;
		outfile << setw(50) << left << "Fullerton, CA 92821" << endl;
		outfile << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
		outfile << left << setw(10) << "Date/Time: " 
			<< right << setw(40) << asctime(timeinfo);
		outfile << setw(10) << left << "Employee: "
			<< setw(40) << name << endl;
		outfile << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		outfile << setw(10) << left << "Earnings "
			<< setw(30) << right << "$"
			<< setw(10) << right << pay << endl;
		outfile << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		outfile << setw(50) << left << "Deductions Statutory" << endl;
		outfile << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
		outfile << setw(12) << "" 
			<< setw(26) << left << "Federal Income Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -fedTax << endl;
		outfile << setw(12) << "" 
			<< setw(26) << left << "Social Security Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -ssTax << endl;
		outfile << setw(12) << "" 
			<< setw(26) << left << "Medicare Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -medicareTax << endl;
		outfile << setw(12) << "" 
			<< setw(26) << left << "CA State Tax"
			<< setw(1) << left << "$"
			<< setw(10) << right << -stateTax << endl;
		outfile << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
		outfile << setw(30) << right << "NET PAY"
			<< setw(10) << right << "$"
			<< setw(10) << netPay;

	outfile.close();
}