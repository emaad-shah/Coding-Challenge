#include "tstree.h"

// Constructor for the TSTree
TSTree::TSTree()
{
	// Create an empty tree
	root = NULL;
}

// Deconstructor for the TSTree
TSTree::~TSTree()
{
	// Deallocate all memory with the helper function
	free(root);
}

// Helper function for the destructor
void TSTree::free(Node*& root) 
{
	// Delete all nodes
	if (root == NULL)
		return;
	free(root->left);
	free(root->right);
	free(root->center);
	delete root;
	root = NULL;
}

// Insert a node recursively
void TSTree::rInsert(int data)
{
	// Call the helper function for the recursive insert
	rInsertHelper(data, root);
}

// Recursive insert helper 
void TSTree::rInsertHelper (int data, Node*& r)
{
	// Insert new node
	if (r == NULL)
	{
		// Create new node
		Node* newNode = new Node;
		newNode->data = data;
		newNode->center = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
		r = newNode;
	}
	else if (data < r->data)
		rInsertHelper(data, r->left);
	else if (data > r->data)
		rInsertHelper(data, r->right);
	else if (r->center == NULL)
		rInsertHelper(data, r->center);
}

// Insert a node iteratively
bool TSTree::insert(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->center = NULL;
	newNode->right = NULL;

	// Out of memory, bail
	if (newNode == NULL)
		return false;

	// Tree is empty
	if (root == NULL)
	{
		root = newNode;
		return true;
	}
	
	Node* cur = root;
	while (true)
	{
		// Traverse center sub-tree
		if (data == cur->data)
		{
			if (cur->center == NULL)
			{
				cur->center = newNode;
				break;
			}
			else
			{
				delete newNode; 
				newNode = NULL;
				return false;
			}
		}

		// Traverse left sub-tree
		else if (data < cur->data)
		{
			if (cur->left == NULL)
			{
				cur->left = newNode;
				break;
			}
			else
				cur = cur->left;
		}
		// Traverse right sub-tree
		else
		{
			if (cur->right == NULL)
			{
				cur->right = newNode;
				break;
			}
			else
				cur = cur->right;
		}
	}
	return true;
}

// Delete a node from the tree
void TSTree::del(int data)
{
	// Check if the tree is not empty
	if (!isEmpty())
		delHelper(data, root);
}

// Helper function for deleting the node
void TSTree::delHelper(int data, Node *& cur)
{
	// Data Not found
	if (cur == NULL)
		return;
	// Found the data
	if (data == cur->data)
	{
		// Delete it by calling the deleteNode function
		deleteNode(cur);
		return;
	}
	else if (data < cur->data)
		delHelper(data, cur->left);
	else if (data > cur->data)
		delHelper(data, cur->right);
	else
		delHelper(data, cur->center);
}

// Deletes a given node from the tree
void TSTree::deleteNode(Node *& cur)
{
	// The node was no children, easy delete
	if (cur->right == NULL && cur->left == NULL && cur->center == NULL)
	{
		delete cur;
		cur = NULL;
	}

	// Delete a node with one sub-tree
	else if (cur->right == NULL && cur->center == NULL)
	{
		Node* tmp = cur;
		cur = cur->left;
		delete tmp;
		tmp = NULL;
	}

	// Delete a node with one subtree
	else if (cur->left == NULL && cur->center == NULL)
	{
		Node* tmp = cur;
		cur = cur->right;
		delete tmp;
		tmp = NULL;
	}

	// If the node has two subtrees,
	else if (cur->left != NULL && cur->right != NULL && cur->center == NULL)
	{
		int min = cur->right->data;
		// Delete node with the smallest value from the right subtree
		deleteMin(min, cur->right);
		// Put the minimum value in the current node
		cur->data = min;
	}

	// Delete center node
	else
	{
		Node* tmp = cur->center;
		delete tmp;
		tmp = NULL;
		cur->center = NULL;
	}
}

// Finds and delete the object of the 
// minimum value from the right substree
void TSTree::deleteMin(int &min, Node *& cur)
{
	if (cur == NULL)
		return;
	deleteMin(min, cur->left);
	deleteMin(min, cur->right);
	if (cur->data <= min)
	{
		min = cur->data;
		deleteNode(cur);
	}
}

// Display contents of the tree
void TSTree::display()
{
	// Call the display helper function
	if (isEmpty())
		cout << "Tree is empty" << endl;
	else
		displayHelper(root);
	cout << endl;
}

// Display helper function
void TSTree::displayHelper(Node *& cur)
{
	if (cur == NULL)
		return;
	displayHelper(cur->center);
	displayHelper(cur->left);
	cout << cur->data << " ";
	displayHelper(cur->right);
}

// Checks if list is empty
bool TSTree::isEmpty()
{
	return root == NULL;
}

int main(void)
{
	// Create a TSTree Object
	TSTree t, t2, t3;

	int array[] = { 5, 4, 9, 5, 7, 2, 2 };
	int size = sizeof(array) / sizeof(*array);

	// Iterative insert
	for (int i = 0; i < size; i++)
		t.insert(array[i]);
	t.display();

	// Delete
	for (int i = 0; i < size; i++)
		t.del(array[i]);
	t.display();

	// Recursive insert
	for (int i = 0; i < size; i++)
		t2.rInsert(array[i]);
	t2.display();

	// Delete
	for (int i = 0; i < size; i++)
		t2.del(array[i]);
	t2.display();

	// Other test cases
	t3.del(2);
	t3.del(10);
	t3.display();
	t3.insert(5);
	t3.insert(5);
	t3.insert(5);
	t3.rInsert(5);
	t3.display();
	t3.del(5);
	t3.display();
	t3.del(5);
	t3.display();

	system("pause");
	return 0;
}
 


