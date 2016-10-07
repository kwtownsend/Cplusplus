//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallHW02.cpp
//Credits:

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;

//function proto
bool haveMoreEmployee();
string currentTime();
void getNameInfo(string& employeeName, string& customerName);
string getEmployeeName(string& employeeName);
string getCustomerName(string& customerName);
void generatePaySlip();
double computePay(double& taxCost, double frameArea, char frameType, double frameSize, string frameColor, double& typeCost, double& subtotal, double& flatCost, double& colorCost, double& glassCost, double& cardboardCost);
double heightFrame();
double frameWidth();
string getColor();
double getFrameSize(double height, double width);
double getColorCost(string frameColor, double frameSize);
char getFrameType();
double getTypeCost(char frameType, double frameSize);
double getFrameArea(double height, double width);
double getCardboardCost(double frameArea);
double getGlassCost(double frameArea);
double getSubtotal(double colorCost, double typeCost, double glassCost, double cardboardCost);
double getFlatCost(double colorCost, double typeCost);
double getTaxCost(double subtotal);
void print(string currentTime, string employeeName, char frameType, string customerName, double height, double width, string frameColor, double flatCost, double cardboardCost, double glassCost, double subtotal, double taxCost, double totalCost);
void frameCustom(string& frameColor, double& frameArea, char& frameType, double& frameSize, double height, double width);
void getFrameInfo(double& width, double& height, string& frameColor, double& frameArea, char& frameType, double frameSize);

//Function Name: main
//Purpose: to generate payslip and ask for more customers
//Return type: int
//Input parameters: none
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: generatePaySlip(), haveMoreEmployee()
//Error messages: none

int main()
{
	do
	{
		generatePaySlip();
	}
	while (haveMoreEmployee());
	
		return 0;
}

//Function Name: haveMoreEmployee();
//Purpose: to loop in if you have more employee
//Return type: bool
//Input parameters: none
//Output parameters: none
//User inputs: moreEmployee
//User outputs: again
//Functions called: none
//Error messages: Invalid Answer

bool haveMoreEmployee()
{
	bool valid;
	char moreEmployee;
	bool again;

	do
	{
		cout << endl << "Do you have another Employee? (Y/N)" << endl;
		cin >> moreEmployee;
		cin.ignore();
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

//Function Name: currentTime
//Purpose: to give the current time
//Return type: string
//Input parameters: none
//Output parameters: currentTime
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

string currentTime()
{
	string currentTime;
	//setting up time
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	currentTime = asctime(timeinfo);
	return currentTime;
}

//Function Name:getNameInfo();
//Purpose: to get the employee and customer name
//Return type: void
//Input parameters: employeeName, customerName, 
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: getEmployeeName(), getCustomerName()
//Error messages: none

void getNameInfo(string& employeeName, string& customerName)
{
	getEmployeeName(employeeName);
	getCustomerName(customerName);
}

//Function Name: getEmployeeName()
//Purpose: to get employeeName
//Return type: string
//Input parameters: employeeName
//Output parameters: employeeName
//User inputs: employeeName
//User outputs:none
//Functions called: none
//Error messages:invalid name

string getEmployeeName(string& employeeName)
{
	//Get customer, and employee name
	bool valid;
	string name;

	do
	{
		cout << "Who is the current employee?" << endl;
		getline(cin, employeeName);

		if (employeeName == "")
		{
			cout << "Invalid Name" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);


	return employeeName;
}

//Function Name:getCustomerName()
//Purpose: to get customer name
//Return type: string
//Input parameters: customerName
//Output parameters: customerName
//User inputs: customerNAme
//User outputs:none
//Functions called: none
//Error messages: invalid Name

string getCustomerName(string& customerName)
{
	bool valid;
	do
	{
		cout << "What is the Customers Name?" << endl;
		getline(cin, customerName);

		if (customerName == "")
		{
			cout << "Invalid Name" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);
	
	return customerName;
}
//Function Name: generatePaySlip()
//Purpose: to put all the functions together
//Return type: void
//Input parameters: none
//Output parameters: none
//User inputs:none
//User outputs:none
//Functions called: getNameInfo(), frameWidth(), heightFrame(), frameSize(), getFrameInfo(), computePay(), print()
//Error messages: none

void generatePaySlip()
{
	double height, width, frameArea, frameSize, totalCost, typeCost, cardboardCost, glassCost, colorCost, taxCost, subtotal, flatCost;
	string frameColor, currentTime;
	char frameType;
	string customerName, employeeName;

	getNameInfo( employeeName, customerName );
	width = frameWidth();
	height = heightFrame();
	frameSize = getFrameSize(height, width);
	
	getFrameInfo(width, height, frameColor, frameArea, frameType, frameSize);
	totalCost = computePay(taxCost, frameArea, frameType, frameSize, frameColor, typeCost, subtotal, flatCost, colorCost, glassCost, cardboardCost);
	print(currentTime, employeeName, frameType, customerName, height, width, frameColor, flatCost, cardboardCost, glassCost, subtotal, taxCost, totalCost);
}

//Function Name: frameCustom()
//Purpose: to intialize frame custom functions
//Return type: void
//Input parameters: frameColor, frameArea, frameType, frameSize, height, width
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: getColor(), getFrameType(), getFrameArea()
//Error messages: none

void frameCustom(string& frameColor, double& frameArea, char& frameType, double& frameSize, double height, double width)
{

	frameColor = getColor();
	frameType = getFrameType();
	frameArea = getFrameArea(height, width);

}

//Function Name: getFrameInfo()
//Purpose: to initialize frameCustom
//Return type: void
//Input parameters: width, height, frameColor, frameArea, frameType, frameSize
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: frameCustom()
//Error messages: none

void getFrameInfo(double& width, double& height, string& frameColor, double& frameArea, char& frameType, double frameSize)
{

	frameCustom(frameColor, frameArea, frameType, frameSize, height, width);
}

//Function Name:computePay()
//Purpose: to get all the costs
//Return type: double
//Input parameters: taxCost, frameArea, frameType, frameSize, frameColor, typeCost, subtotal, flatCost, colorCost, glassCost, cardboardCost
//Output parameters: totalCost
//User inputs: none
//User outputs: none
//Functions called: getColorCost(), getTypeCost(), getGlassCost(), getCardboardCost(), getSubtotal(), getTaxCost(), getFlatCost()
//Error messages: none

double computePay(double& taxCost, double frameArea, char frameType, double frameSize, string frameColor, double& typeCost, double& subtotal, double& flatCost, double& colorCost, double& glassCost, double& cardboardCost)
{
	colorCost = getColorCost(frameColor, frameSize);
	typeCost = getTypeCost(frameType, frameSize);
	glassCost = getGlassCost(frameArea);
	cardboardCost = getCardboardCost(frameArea);
	subtotal = getSubtotal(colorCost, typeCost, glassCost, cardboardCost);
	
	taxCost = getTaxCost(subtotal);
	flatCost = getFlatCost(colorCost, typeCost);


	double totalCost;
	totalCost = taxCost + subtotal;

	return totalCost;
}

//Function Name: heightFrame()
//Purpose: to get the frames height
//Return type: double
//Input parameters: none
//Output parameters: height
//User inputs: height
//User outputs: none
//Functions called: none
//Error messages: invalid height

double heightFrame()
{
	//Get height, and width of frame
	double height;
	bool valid;
	do
	{
		cout << "What is the Frames Height?" << endl;
		cin >> fixed >> setprecision(2) >> height;
		
		if (height <= 3 || height >= 72)
		{
			cout << "Invalid Height, Please enter again" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	return height;
}

//Function Name: frameWidth()
//Purpose: to get frame width
//Return type: double
//Input parameters: none
//Output parameters: width
//User inputs: width
//User outputs: none
//Functions called: none
//Error messages: invalid width

double frameWidth()
{
	//get frame width
	double width;
	bool valid;
	do
	{
		cout << "What is the Frames Width?" << endl;
		cin >> fixed >> setprecision(2) >> width;
		
		if (width <=3 || width >=72)
		{
			cout << "Invalid Width, Please enter again" << endl;
			valid = false;
		}
		else
		{
			valid = true;
		}
	}while (!valid);

	return width;
}

//Function Name: getcolor()
//Purpose: to get frame color
//Return type: string
//Input parameters: none
//Output parameters: frameColor
//User inputs: frameColor
//User outputs: none
//Functions called: none
//Error messages: invalid answer

string getColor()
{
	string frameColor;
	char frameWhite;
	bool valid;
	//get color
	do
	{
		cout << "Would you like the Frame Colored? 'Y' for yes, and 'N' for no" << endl;
		cin >> frameWhite;
		frameWhite = toupper(frameWhite);

		if(frameWhite == 'N' || frameWhite == 'Y')
		{
			valid = true;
		}
			else
			{
				cout << "Invalid" << endl;
				valid = false;
			}
		}while (!valid);


	if (frameWhite == 'N')
	{
		frameColor = "white";
	}

	else if (frameWhite == 'Y')
	{
		cout << "What color would you like?" << endl;
		cin >> frameColor;
	}

	return frameColor;
}

//Function Name: getFrameSize()
//Purpose: to get the constant size for the cost
//Return type: double
//Input parameters: height, width
//Output parameters: frameSize
//User inputs: none
//User outputs: noen
//Functions called: none
//Error messages: none

double getFrameSize(double height, double width)
{
	 double frameSize = ((height * 2) + (width * 2) + 4);
	return frameSize;
}

//Function Name:getColorCost()
//Purpose: to get the cost if their is a color
//Return type: double
//Input parameters: frameColor, frameSize
//Output parameters: colorCost
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

double getColorCost(string frameColor, double frameSize)
{
	double colorCost;
	//adding color cost 
	if (frameColor != "white")
	{
		colorCost = frameSize * .10;
	}
	else
	{
		colorCost = 0;
	}
	
	return colorCost;
}

//Function Name: getFrameType
//Purpose: to get the kind of frame
//Return type: char
//Input parameters: none
//Output parameters: frameType
//User inputs: frameType
//User outputs: none
//Functions called: none
//Error messages: invalid answer

char getFrameType()
{
	char frameType;
	bool valid;
	//Frame type
	do
	{
		cout << "Would you like a fancy frame, (Type 'F') or a regular frame (Type 'R')?" << endl;
		cin >> frameType;
		frameType = toupper(frameType);

		if (frameType == 'F' || frameType == 'R')
		{
			valid = true;
		}
			else
			{
				cout << "Invalid" << endl;
				valid = false;
			}
		}while (!valid);
	return frameType;
}

double getTypeCost(char frameType, double frameSize)
{
	//Frame type added cost
	double typeCost;
		if (frameType == 'F')
		{
			typeCost = frameSize * .25;
		}
		else
		{
			typeCost = frameSize * .15;
		}
	return typeCost;
}

//Function Name: getFrameArea()
//Purpose: get frame Area for cost
//Return type: double
//Input parameters: height, width
//Output parameters: frameArea
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

double getFrameArea(double height, double width)
{
	double frameArea = (height * width);

	return frameArea;
}

//Function Name: getCardboardCost()
//Purpose: to get cardboard cost
//Return type: double 
//Input parameters: frameArea
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

double getCardboardCost(double frameArea)
{
	double cardboardCost;
	cardboardCost = frameArea * .02;

	return cardboardCost;
}

//Function Name: getGlassCost()
//Purpose: get glass Cost
//Return type: double 
//Input parameters: frameArea
//Output parameters: glassCost
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

double getGlassCost(double frameArea)
{
	double glassCost;
	glassCost = frameArea * .07;

	return glassCost;
}

//Function Name: getSubtotal
//Purpose: to get the subtotal
//Return type: double
//Input parameters: colorCost, typeCost, glassCost, cardboardCost
//Output parameters: subtotal
//User inputs: none
//User outputs: none
//Functions called: noen
//Error messages: none

double getSubtotal(double colorCost, double typeCost, double glassCost, double cardboardCost)
{
	double subtotal;
	subtotal = colorCost + typeCost + glassCost + cardboardCost;
	return subtotal;
}

//Function Name: getFlatCost
//Purpose: to get flat cost
//Return type: double
//Input parameters: colorCost, typeCost
//Output parameters: flatCost
//User inputs: noen
//User outputs:  none
//Functions called: none
//Error messages: none

double getFlatCost(double colorCost, double typeCost)
{
	double flatCost;
	flatCost = colorCost + typeCost;

	return flatCost;
}

//Function Name: getTaxCost()
//Purpose: to get tax cost
//Return type: double
//Input parameters: subtotal
//Output parameters: taxCost
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

double getTaxCost(double subtotal)
{
	double taxCost;
	const double taxrate = .0925;
	taxCost = subtotal * taxrate;

	return taxCost;
}

//Function Name: print()
//Purpose: to print out the results
//Return type: void
//Input parameters: currentTime, employeeName, frameType, customerName, height, width, frameColor, flatCost, cardboardCost, glassCost, subtotal, taxCost, totalCost
//Output parameters: none
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

void print(string currentTime, string employeeName, char frameType, string customerName, double height, double width, string frameColor, double flatCost, double cardboardCost, double glassCost, double subtotal, double taxCost, double totalCost)
{
	//formatting and output
	cout << left << setw(15) << "KENDALLS FRAMES" << right << setw(35) << "Purchase Order" << endl;
	cout << left << setw(50) << "714 - 756 - 1234" << endl;
	cout << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << left << setw(10) << "Date/Time: " 
		<< right << setw(40) << currentTime;
	cout << left << setw(15) << "Order taken by: "
		<< left << setw(35) << employeeName << endl;
	cout << left << setw(10) << "Customer: " 
		<< left << setw(40) << customerName << endl;
	cout << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << left << setw(12) << "Frame Height"
		<< setw(38) << setfill('.') << fixed << setprecision(2) << right << height << endl;
	cout << left << setw(11) << "Frame Width"
		<< setw(39) << setfill('.') << fixed << setprecision(2) << right << width << endl;
	cout << left << setw(11) << "Frame Type"
		<< setw(39) << setfill('.') << right << frameType << endl;
	cout << left << setw(7) << "Color"
		<< setw(43) << setfill('.') << right << frameColor << endl;
	cout << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << left << setw(6) << "Frames" 
		<< setw(34) << right << "$" 
		<< setw(10) << right << fixed << setprecision(2) << flatCost << endl;
	cout << left << setw(14) << "Cardboard Back" 
		<< setw(26) << right << "$" 
		<< setw(10) << right << fixed << setprecision(2) << cardboardCost << endl;
	cout << left << setw(5) << "Glass"
		<< setw(35) << right << "$"
		<< setw(10) << right << fixed << setprecision(2) << glassCost << endl;
	cout << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << setw(35) << right << "Subtotal"
		<< setw(5) << right << "$"
		<<setw(10) << right << fixed << setprecision(2) << subtotal << endl;
	cout << setw(35) << right << "Tax (9.25%)"
		<< setw(5) << right << "$"
		<< setw(10) << right << fixed << setprecision(2) << taxCost << endl;
	cout << setw(35) << right << "Total"
		<< setw(5) << right << "$"
		<< setw(10) << right << fixed << setprecision(2) << totalCost << endl;
	cout << setw(50) << setfill('=') << '\n' << setfill(' ') << endl;
	cout << "THANK YOU for your order." << endl;
}