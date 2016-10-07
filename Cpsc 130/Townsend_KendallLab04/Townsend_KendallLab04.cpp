//Townsend, Kendall
//894121409
//CPSC 121 Section 5
//Spring 2011
//LTownsend_KendallLab04.cpp
//Credits: Lisa, Nathan Niyomtham

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>


using namespace std;


//function prototype
void generatePaySlip();
void getUserInfo(double& weight, double& height, double& age, char& gender);
double getWeight();
double getHeight();
double getAge();
char getGender();
double getBMR(double weight, double height, double age, char gender);
void print(char gender, double age, double height, double weight, double BMR);
void displayPrint(char gender, double age, double height, double weight, double BMR);

//Function Name: main()
//Purpose:This program determines the BMR, through age, weight, height, and gender
//Return type: int
//Input parameters: None
//Output paramters: None
//User inputs: none
//User outputs: none
//Functions called: generatePaySlip();
//Error messages: none



int main()
{
	generatePaySlip();
}


//Function Name: generatePaySlip();
//Purpose: To gather all the information needed for the program
//Return type: void
//Input parameters: none
//Output paramters: none
//User inputs: none
//User outputs: none 
//Functions called: getUserInfo(), getBMR(), print(), displayPrint()
//Error messages: none

void generatePaySlip()
{
	double weight, height, age, BMR;
	char gender;
	getUserInfo(weight, height, age, gender);
	BMR = getBMR(weight, height, age, gender);
	print(gender, age, height, weight, BMR);
	displayPrint(gender, age, height, weight, BMR);
}

 //Function Name: getUserInfo();
//Purpose: to gather weight, height, age, and gender
//Return type: void
//Input parameters: weight, height, age, gender
//Output paramters: none
//User inputs:none
//User outputs: none
//Functions called: getWeight(), getHeight(), getAge(), getGender()
//Error messages: none

void getUserInfo(double& weight, double& height, double& age, char& gender)
{
	weight = getWeight();
	height = getHeight();
	age = getAge();
	gender = getGender();

}

 //Function Name: getWeight();
//Purpose: to find the users weight
//Return type: double
//Input parameters: none
//Output parameters: weight
//User inputs: weight
//User outputs: none
//Functions called: none
//Error messages: Invalid Weight

double getWeight()
{
	double weight;

	//get weight and validate
	bool valid;
	do
	{
		cout << "Enter your Weight in Pounds" << endl;
		cin >> weight;
		
		if (weight > 800 || weight < 0)
		{
		cout << "Invalid Weight" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	return weight;
}
	
//Function Name: getHeight();
//Purpose: to get the users height
//Return type: double
//Input parameters: none
//Output paramters: height
//User inputs: height
//User outputs: none
//Functions called: none
//Error messages: Invalid Height

double getHeight()
{
	bool valid;
	double height;
	do
	{
		cout << "Enter your Height in Inches: " << endl;
		cin >> height;
		
		if (height >= 100 || height < 0)
		{
		cout << "Invalid Height" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

return height;
}
	
//Function Name: getAge();
//Purpose: to get the users age
//Return type: double
//Input parameters: none
//Output paramters: age
//User inputs: age
//User outputs: none
//Functions called:none
//Error messages: Invalid Age

 double getAge()
 {
	double age;
	bool valid;
	do
	{
		cout << "Enter your Age in years: " << endl;
		cin >> age;
		
		if (age >= 150 || age < 0)
		{
		cout << "Invalid Age" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	return age;
 }

 //Function Name: getGender()
//Purpose: to get users Gender
//Return type: char
//Input parameters: none
//Output paramters: gender
//User inputs: gender
//User outputs: none
//Functions called:none
//Error messages: Invalid gender

 char getGender()
{
	char gender;
	bool valid;
		do
	{
		cout << "Enter if you are a Male/Female, With M or F" << endl;
		cin >> gender;
		gender = tolower(gender);
		
		if(gender != 'm' && gender != 'f')
		{
		cout << "Invalid gender" << endl;
		valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);
 
	return gender;
 }

 //Function Name: getBMR
//Purpose: to determine the BMR from the gender, height, age, and weight
//Return type: double
//Input parameters: weight, height, age, gender
//Output paramters: BMR
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

double getBMR(double weight, double height, double age, char gender)
{
	double BMR;
	//if its male use this for BMR
	if ( gender == 'm')
	{

		BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
	}

	// remaining answer is only female so, if female use this for BMR
	else
	{
		BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
	}
	return BMR;
}

 //Function Name: void print();
//Purpose: to print the results into a .txt file
//Return type: void
//Input parameters: gender, age, height, weight, BMR
//Output paramters: none
//User inputs: none
//User outputs: gender, age, height, weight, BMR
//Functions called: none
//Error messages: none

void print(char gender, double age, double height, double weight, double BMR)
{
	ofstream outfile;
	string filename = "Your BMR.txt";
	outfile.open(filename);

	outfile << setw(20) << setfill('=') << '\n' << setfill(' ') << endl;
	outfile << setw(10) << left << "Gender" << setw(10) << right << gender << endl;
	outfile << setw(10) << left << "Age" << setw(10) << right << age << endl;
	outfile << setw(10) << left << "Height" << setw(10) << right << fixed << setprecision(2) << height << endl;
	outfile << setw(10) << left << "Weight" << setw(10) << right << fixed << setprecision(2) << weight << endl;
	outfile << setw(20) << setfill('-') << '\n' << setfill(' ') << endl;
	outfile << setw(10) << left << "BMR" << setw(10) << right << fixed << setprecision(2) << BMR << endl;
	outfile << setw(20) << setfill('=') << '\n' << setfill(' ') << endl;

	outfile.close();
}

 //Function Name: void displayPrint();
//Purpose: to display the results into the w32 prompt
//Return type: void
//Input parameters: gender, age, height, weight, BMR
//Output paramters: none
//User inputs: none
//User outputs: gender, age, height, weight, BMR
//Functions called: none
//Error messages: none

void displayPrint(char gender, double age, double height, double weight, double BMR)
{
	cout << setw(20) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << setw(10) << left << "Gender" << setw(10) << right << gender << endl;
	cout << setw(10) << left << "Age" << setw(10) << right << age << endl;
	cout << setw(10) << left << "Height" << setw(10) << right << fixed << setprecision(2) << height << endl;
	cout << setw(10) << left << "Weight" << setw(10) << right << fixed << setprecision(2) << weight << endl;
	cout << setw(20) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(10) << left << "BMR" << setw(10) << right << fixed << setprecision(2) << BMR << endl;
	cout << setw(20) << setfill('=') << '\n' << setfill(' ') << endl;
}
