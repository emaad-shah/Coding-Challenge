//------------------------------------------------------------
// Copyright:	Syed Shah 2014
//
// Task:	Implement insert and delete in a tri-nary tree. 
//		A tri-nary tree is much like a binary tree but 
//		with three child nodes for each parent instead 
//		of two -- with the left node being values less
//		than the parent, the right node values greater
//		than the parent, and the middle nodes values
//		equal to the parent
//
// IDE:		Visual Studio Express 2013
//
// Assumptions: With the current implementation, a particular 
//		node in the tree will only have one center 
//		node. The center node will not spawn a subtree
//
// Limitations: The current implementation stores an int the 
//		tree. The Tree has the capacity to store any
//		object with minimum modification
//------------------------------------------------------------
#ifndef TSTREE_H
#define TSTREE_H
#include <iostream>
#include <fstream>

using namespace std;

class TSTree
{
	public:
		// Constructor for the TSTree
		TSTree();
		// Deconstructor for the TSTree
		~TSTree();
		// Insert a node iteratively
		bool insert(int);
		// Insert a node recursively
		void rInsert(int);
		// Delete a node from the tree
		void del(int);
		// Display contents of the tree
		void display();
		// Checks if list is empty
		bool isEmpty();

	private:
		// TSTree Node
		struct Node
		{
			Node* left;
			Node* center;
			Node* right;
			int data;
		};
		Node *root;

		// Helper function for the destructor
		void free(Node*&);
		// Recursive insert helper 
		void rInsertHelper(int, Node*&);
		// Helper function for deleting the node
		void delHelper(int, Node *&);
		// Deletes a given node from the tree
		void deleteNode(Node *&);
		// Finds and delete the object of the 
		// minimum value from the right substree
		void deleteMin(int&, Node *&);
		// Display helper function
		void displayHelper(Node*&);
};

#endif
