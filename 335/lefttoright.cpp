// Assignment 1: Alternating disks problem, left-to-right algorithm                                                                                                                                                               
// Kendall Townsend                                                                                                                                                                                         
// Given 2n alternating disks (light, dark) the program reads the number of single color disks                                                                                                                                    
// (light or dark), arranges the disks in the correct order and outputs the number of swaps                                                                                                                               
// INPUT: a positive integer n and a list of 2n disks of alternating colors dark-light, starting with dark                                                                                                                                                                        
// OUTPUT: a list of 2n disks, the first n disks are light, the next n disks are dark,                                                                                                                               
// and an integer m representing the number of moves to move the dark ones after the light
//  Gnu compiler: g++ -c -m64 -Wall -l lefttoright.lis -o lefttoright.o lefttoright.cpp
//  Gnu Linker: g++ -m64 -o lefttoright.out lefttoright.o

                                                                                                                                                                      
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;
void print_disks(int n, string disks)
{
	cout << "Disks: ";
	for(int l=0; l<n; l++)
	{
		if ( disks[l] == 1)
			cout << "D" << " ";
		else
			cout << "0" << " ";
	}
		cout << endl;
}
 
 
int main() 
{
  int n, m = 0, k, i;
  string disks;
  // display the header                                                                                                                                                                                  
  cout << endl << "CPSC 335-03 - Programming Assignment #1" << endl;
  cout << "The alternating disks problem: left-or-right algorithm" << endl;
  cout << "Enter the number of single color disks (light or dark)" << endl;
                                                                                                                                                                      
  cin >> n;   // read the number of disks    
  n = n * 2;
// set the initial configurations for the disks to alternate                                                                                                                                           
  for( i=0; i < n; i++) {
    disks[2*i] = 1;
    disks[2*i+1] = 0;   
}
  // print the initial configuration of the list of disks                                                                                                                                                
  cout << "Initial configuration" << endl;
  print_disks(n,disks);
  cout << endl;
  // loop to push light one before darks ones 
int x, y = 0;
x = (n /2);

	for(int z=0; z< n; z++)
	{
		if (x!=y)
		{
			y=0;

// CHECK TO SEE IF YOU NEED TO SWAP DARK OVER STARTING FROM LEFT TO RIGHT
			for (k=0;  k < n ; k++) 
  			{ 
				if ( (disks[k] == 1) && (disks[k+1] == 0) && (k+1 < n) )
				{
					swap(disks[k], disks[k+1]);
					// INCREMENT AFTER YOU SWAP
  					m++;

				}
			}




// CHECK TO SEE IF DONE SORTING BY CHECKING IF ALL DARK ARE TO RIGHT
			for(int w=0; w<n; w++)
			{

				if ( (disks[w] == 1) && ((disks[w+1] == 1) || (w+1 >= n)) && (disks[n-1] == 1) && (y!=x))
				{
					y++;

				}
			}

		} 
 	}

	
	                                                                                                                                                      
  // YOU NEED TO COMPLETE THIS PART OF CODE

  // after shuffling them                                                                                                                                                                                
  cout << "After moving darker ones to the left" << endl;
  print_disks(n, disks);
  // print the total number of moves                                                                                                                                                                     
  cout << "Number of swaps is " << m << endl;
  return EXIT_SUCCESS;
}

