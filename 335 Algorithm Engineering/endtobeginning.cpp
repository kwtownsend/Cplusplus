// Assignment 2: Longest increasing subsequence problem, end-to-beginning algorithm
// Kendall Townsend
// Given a sequence of elements the program finds a subsequence of it in which the subsequence's 
// elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. 
// The program reads the number of elements in the sequence, then the elements and outputs the sorted 
// sequence and the running time. 
// INPUT: a positive integer n and a list of n elements 
// OUTPUT: a longest increasing subsequence of the initial sequence
//  Gnu compiler: g++ -std=c++0x -c -m64 -Wall -l endtobeginning.lis -o endtobeginning.o endtobeginning.cpp
//  Gnu Linker: g++ -m64 -o endtobeginning.out endtobeginning.o
 

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>

using namespace std;

void print_sequence(int, float*);
// function to print a sequence, given the number of elements and 
// the actual sequence stored as an array 
int main() 
{
	int n, i, j, max, index;
	float *A, *R;
	int *H;

// display the header 
	cout << endl << "CPSC 335-03 - Programming Assignment #2" << endl;
	cout << "Longest increasing subsequence problem, end-to-beginning algorithm" << endl;
	cout << "Enter the number of elements in the sequence" << endl;

// read the number of elements 

	cin >> n;

// allocate space for the input sequence and array H 

	A = new float[n];
	H = new int[n];

// read the sequence 
	cout << "Enter the elements in the sequence" << endl;
	for( i=0; i < n; i++)
		cin >> A[i];

// print the sequence 
	cout << "Input sequence" << endl;
	print_sequence(n,A);

// Start the chronograph to time the execution of the algorithm 
	auto start = chrono::high_resolution_clock::now();

// loop to populate the array H with 0 values 
	for(i=0; i< n; i++)
		H[i] = 0;

// loop to calculate the values of array H 
int count = 0;

float temp, last;
//temp is the variable that is set to each subsequent number that is higher
//last is used so that if a better order is found it will maximize subsequence
// i.e. 1, 10, 2 it'll change the order from 1, 10 to 1, 2.
for ( i = n-2; i>= 0; i--) 
{
		temp = A[i]; //set temp to first number before any new subsequent numbers
	for ( j = i+1; j < n ; j++)
	{
		if( temp < A[j] ) //compare temp with number after it to see if its larger
		{
			count++; //if larger add one to number of jumps
			last = temp; //set number before jump in case better option comes up
			temp = A[j]; //set temp to new number that is found to be larger then old
		}

		else if( temp > A[j] && A[j] > last && count != 0) //special case to find better better subsequent number
		{
			temp = A[j];

		}
	}
	H[i] = count; //after loop set count to that spot in array for amount of jumps
	count = 0; //set count to 0 for next loop
}



// calculate in max the length of the longest subsequence by adding 1 
// to the maximum value in H 

	max = H[0];
	for( i=1; i< n; i++)
	{
		if (max < H[i])
		{
			max = H[i];
			max ++;
		}
	}
max = max +1;
 // allocate space for the subsequence R 

 	R = new float[max];

 // add elements to R by whose H's values are in decreasing order, starting 
 // with max-1 
 // store in index the H values sought 

	index = max - 1; //set index to maximum number of subsequent numbers
	count = 0;    // set count to 0
	for(i=0; i< n; i++)
	{
		if (H[i] == index) //compare numbers in array 'H' with index
		{
			R[count] = A[i]; //if index is same as number in array 'H' take the actual number from array 'A'
			count++;         //increment for next number to be added to array
			index = index - 1; //decrease the index so you can find the number associated with the next highest number of subsequent numbers.
		}
	}
 // End the chronograph to time the loop 
 auto end = chrono::high_resolution_clock::now();

 // write the output 
	cout << "The longest increasing subsequence has length " << endl;
	cout << max << endl;
	cout << "The longest increasing subsequence is" << endl;
	print_sequence(max, R);

// print the elapsed time in seconds and fractions of seconds 
	int microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
	double seconds = microseconds / 1E6;
	cout << "elapsed time: " << seconds << " seconds" << endl;
// de-allocate the dynamic memory space 
	delete [] A;
	delete [] H;
	delete [] R;

return EXIT_SUCCESS;
}

void print_sequence(int n, float *seq)
{
	for(int i=0; i<n; i++)
	{
		cout << seq[i] << " ";
	}
cout << endl;
// function to print a sequence, given the number of elements and 
// the actual sequence stored as an array 
// n represents the number of elements in the sequence 
// seq represents the actual sequence 
// WRITE THE CODE TO PRINT THE ELEMENTS OF A SEQUNCE seq WITH n ELEMENTS
}
