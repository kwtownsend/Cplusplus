#include <iostream>
using namespace std;
#include <iomanip>
#include <string>

class BST
{
private: struct node
		 {
			 int ID;
			 string name;
			 float balance;
			 node *left, *right;
		 };
		 node* root;

public:
	BST() {root = NULL; }
	
	void insert(node* &p, int ID, string name, float balance)
	{
		if (p == NULL)
		{
			p = new(node); p -> ID = ID; p -> name = name; p -> balance = balance;
			p -> left = NULL; p -> right = NULL;
		}
		else if (ID < p -> ID ) 
			insert(p -> left, ID, name, balance);
		else 
			insert( p -> right, ID, name, balance);
	}

	void display(node* p)
	{
		if (p != NULL)
		{
			display(p -> left);
			cout << setw(10) << left << p -> ID;
			cout << setw(10) << left << p -> name;
			cout << setw(10) << left << p -> balance << endl;
			display( p -> right);
		}
	}

	void deposit(node* p, int ID, int x)
	{
		if (p -> ID == ID)
		{
			p -> balance = (p -> balance + x);
			cout << "Your balance now is " << p ->balance;
		}
		else if (ID < p -> ID ) 
			deposit(p -> left, ID, x);
		else 
			deposit( p -> right, ID, x);


	}

	void withdraw(node* p, int ID, int x)
	{
		if (p -> ID == ID)
		{
			p -> balance = (p -> balance - x);
			cout << "Your balance now is " << p -> balance;
		}
		else if (ID < p -> ID ) 
			withdraw(p -> left, ID, x);
		else 
			withdraw( p -> right, ID, x);
	}

	void SearchID(node* p, int x)
	{
		if (p == NULL)
		{
			cout << "ID " << x << " does not exist" << endl;
		}
		else if (x == p -> ID)
		{
			cout << setw(10) << left << p -> ID;
			cout << setw(10) << left << p -> name;
			cout << setw(10) << left << p -> balance << "\t";
		}
		else if ( x < p -> ID)
		{
			SearchID( p -> left, x);
		}
		else
		{
			SearchID(p -> right, x);
		}
	}

	void insert(int ID, string name, float balance)
	{
		insert(root, ID, name, balance);
	}

	void display()
	{
		display(root);
	}

	void deposit(int ID, int x)
	{
		deposit(root, ID, x);
	}

	void withdraw(int ID, int x)
	{
		withdraw(root, ID, x);
	}
	
	void SearchID(int x)
	{
		SearchID(root, x);
	}
};