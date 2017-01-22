//Townsend, Kendall
//894121409
//CPSC131 Section 2
//Fall 2012
//Project no.1 Part 1A

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

//function prototype
void FindDifferentElements(int& uppercase, int& lowercase, int& digits, int& vowels);
int FindUppercase(int& uppercase, char c);
int FindLowercase(int& lowercase, char c);
int FindDigits(int& digits, char c);
int FindVowels(int& vowels, char c);

//Function Name: main
//Purpose: To take in a user input and determine the uppercase, lowercase, numbers, and vowels
//Return type: int
//Input parameters: none 
//Output parameters:  none
//User inputs: none
//User outputs: none
//Functions called: FindDifferentElements()
//Error messages: none

int main()
{
	int uppercase = 0, lowercase = 0, digits = 0, vowels = 0;

	cout << "Enter a Sentence:";
	
	FindDifferentElements(uppercase, lowercase, digits, vowels);

	cout << setw(39) << left << "No. of uppercase letters"
		<<setfill('.') << setw(1) << uppercase << endl;
	cout << setw(39) << left << "No. of lower case letters"
		<<setfill('.') << setw(1) << lowercase << endl;
	cout << setw(39) << left << "No. of digits"
		<< setfill('.') << setw(1) << digits << endl;
	cout << setw(39) << left << "no. of vowels"
		<< setfill('.') << setw(1) << vowels << endl;

}

//Function Name:FindDifferentElements
//Purpose: To find the amount of uppercase, lowercase, number, and vowels in the inputted word.
//Return type: Void
//Input parameters: uppercase, lowercase, digits, vowels
//Output parameters: none
//User inputs: c
//User outputs: none
//Functions called: FindUppercase(), FindLowerCase(), FindDigits(), FindVowels()
//Error messages: None

void FindDifferentElements(int& uppercase, int& lowercase, int& digits, int& vowels)
{
	char c;
	cin >> noskipws;
	while(cin.get(c), c != '\n')
	{
		FindUppercase(uppercase, c);
		FindLowercase(lowercase, c);
		FindDigits(digits, c);
		FindVowels(vowels, c);
	}
}

//Function Name: FindUppercase
//Purpose: To determine the amount of uppercase chars their are.
//Return type: int
//Input parameters: uppercase, c
//Output parameters: uppercase
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

int FindUppercase(int& uppercase, char c)
{
	if (isupper(c))
	{
		uppercase++;
	}
	return uppercase;
}

//Function Name: FindLowercase
//Purpose: To determine the amount of lowercase chars their are.
//Return type: int
//Input parameters: lowercase, c
//Output parameters: lowercase
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

int FindLowercase(int& lowercase, char c)
{
	if (islower(c))
	{
		lowercase++;
	}
	return lowercase;
}

//Function Name: FindDigits
//Purpose: To determine the amount of number chars their are.
//Return type: int
//Input parameters: digits, c
//Output parameters: digits
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

int FindDigits(int& digits, char c)
{
	if (isdigit(c))
	{
		digits++;
	}
	return digits;
}

//Function Name: FindVowels
//Purpose: To determine the amount of vowel chars their are.
//Return type: int
//Input parameters: vowels, c
//Output parameters: vowels
//User inputs: none
//User outputs: none
//Functions called: none
//Error messages: none

int FindVowels(int& vowels, char c)
{
	tolower('c');
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u')
	{
		vowels++;
	}
	return vowels;
}