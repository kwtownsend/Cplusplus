//Townsend, Kendall
//894121409
//CPSC121 Section 5
//Spring 2011
//Townsend_KendallHW01.cpp
//Credits:

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;

//Function Name: main()
//Purpose: To recieve specifications on a frame such as size/color, and find subtotal, tax, total.
//Return type: int
//Input parameters: none
//Output parameters: none
//User inputs: employeeName, customerName, frameColor, height, width
//User outputs: cardboardCost, glassCost, flatCost, subtotal, totalCost, taxCost
//Functions called:
//Error messages: "Invalid Height or Width, Please enter again" "Invalid" "Invalid"

int main()
{
	string employeeName, customerName, frameColor;
	double height, width, colorCost, typeCost, cardboardCost, glassCost, flatCost, subtotal, totalCost, taxCost;
	char frameWhite, frameType;
	bool valid;
	
	//setting up time
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	
	//Get customer, and employee name
	cout << "Who is the current employee?" << endl;
	getline(cin, employeeName);
	cout << "Customer Name?" << endl;
	getline(cin, customerName);

	//Get height, and width of frame
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
		frameColor == "white";
	}

	else if (frameWhite == 'Y')
	{
		cout << "What color would you like?" << endl;
		getline(cin, frameColor);
	}
	
	//adding color cost 
	if (frameWhite == 'N')
	{
		colorCost = ((height * 2) + (width * 2) + 4) * .10;
	}
	else
		colorCost = 0;

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

	//Frame type added cost
		if (frameType == 'F')
		{
			typeCost = ((height * 2) + (width * 2) + 4) * .25;
		}
		else
		{
			typeCost = ((height * 2) + (width * 2) + 4) * .15;
		}

	//Flat rate cost Frame cardboard back, and glass
		//cardboard
	cardboardCost = (height * width) * .02;
		//glass
	glassCost =  (height * width) * .07;

	//calculating subtotal
	flatCost = colorCost + typeCost;
	subtotal = flatCost + cardboardCost + glassCost;
		//With Tax
	taxCost = (subtotal * .0925);
	totalCost = taxCost + subtotal;

	//formatting and output
	cout << left << setw(15) << "KENDALLS FRAMES" << right << setw(35) << "Purchase Order" << endl;
	cout << left << setw(50) << "714 - 756 - 1234" << endl;
	cout << setw(50) << setfill('-') << '\n' << setfill(' ') << endl;
	cout << left << setw(10) << "Date/Time: " 
		<< right << setw(40) << asctime(timeinfo);
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
	return 0;
}