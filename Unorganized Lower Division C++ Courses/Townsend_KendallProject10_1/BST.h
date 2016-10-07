#include <iostream>
using namespace std;

class BST
{
private: struct node
		 {
			 int info;
			 node *left, *right;
		 };
		 node* root;

public:
	BST() {root = NULL; }
	void insert(node* &p, int x)
	{
		if (p == NULL)
		{
			p = new(node); p -> info = x;
			p -> left = NULL; p -> right = NULL;
		}
		else if (x < p -> info ) insert (p -> left, x);
		else insert( p -> right, x);
	}

	void display(node* p)
	{
		if (p != NULL)
		{
			display(p -> left);
			cout << p -> info << "\t";
			display( p -> right);
		}
	}

	void TwoChildren(node* p, int& x)
	{
		if ( p!= NULL)
		{
			if( p -> left != NULL && p -> right != NULL)
			{
				x++;
			}
			TwoChildren(p -> left, x);
			TwoChildren(p -> right, x);
		}
	}

	void Search(node* p, int x)
	{
		if (p == NULL)
		{
			cout << "Node " << x << " does not exist" << endl;
		}
		else if (x == p -> info)
		{
			cout << x << " is found";
		}
		else if ( x < p -> info)
		{
			Search( p -> left, x);
		}
		else
		{
			Search(p -> right, x);
		}
	}

	void CountNodes(node* p, int& x)
	{ //based on inorder (LC)(P)(RC)
		if( p != NULL)
		{
			CountNodes(p -> left, x);
			x++;
			CountNodes(p -> right, x);
		}
	}

	void remove(node* &p, int x)
	{
		if ( x < p -> info)
			//look for x in left subtree
			remove(p -> left, x);
		else if ( x > p -> info)
			//look for x in right subtree
			remove (p -> right, x);
		else
			//x found, delete the node
			Deletenode(p);
	}

	void Deletenode(node* &p)
	{
		node* temp; int data; temp = p;
		if(p -> left == NULL) // delete a node w/o a left child
		{ p = p -> right; delete(p); }
		else if (p -> right == NULL) // delete a node w/o right child
		{ p= p -> left; delete(p); }
		else // delete a node with two children
		{
			Find( p -> left, data);
			p -> info = data;
			remove( p -> left, data);
		}
	}

	void Find(node* p, int& x)
	{
		while( p -> right != NULL)
		{
			p = p -> right;
		}
			x = p -> info;
	}

	void insert(int x)
	{
		insert(root, x);
	}

	void CountNodes(int &x)
	{
		CountNodes(root, x);
	}

	void display()
	{
		display(root);
	}

	void TwoChildren(int &x)
	{
		TwoChildren(root, x);
	}

	void remove(int x)
	{
		remove(root, x);
	}
	
	void Search(int x)
	{
		Search(root, x);
	}


};