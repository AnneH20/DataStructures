#include "BST.h"
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a BST that translates a word into Morse Code
*/
using namespace std;

// BST Deconstructor
BST::~BST()
{
	destroy();
}

// Insert Function
bool BST::insert(Node*& node, char data, int location)
{
	if (node == nullptr) {
		node = new Node(data, location);
		return true;
	}
	if (location < node->location)
	{
		return insert(node->left, data, location);
	}
	if (location > node->location)
	{
		return insert(node->right, data, location);
	}
	return false;
}

// Remove Function
bool BST::remove(Node*& node, char data)
{
	if (node == nullptr)
	{
		return false;
	}
	if (data < node->data)
	{
		return remove(node->left, data);
	}
	if (data > node->data)
	{
		return remove(node->right, data);
	}
	int deg = node->degree();

	if (deg == 0) 
	{ 
		delete node; 
		node = nullptr; 
	}
	else if (deg == 1)
	{
		Node* tmp = node;
		if (node->left != nullptr)
		{
			node = node->left;
		}
		delete tmp;
	}
	else
	{
		Node* tmp = node->left;
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}
		node->data = tmp->data;
		remove(node->left, tmp->data);
	}
	return true;
}

// Find Function
bool BST::findlocation(Node* node, char data, int &i)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->data == data)
	{
		i = node->location;
		return true;
	}
	bool x = findlocation(node->left, data, i);
	if (x) // Left of the tree
	{
		return true;
	}
	bool y = findlocation(node->right, data, i);
	if (y) // Right of the tree
	{
		return true;
	}
}

bool BST::find(Node* node, int data)
{
	if (node == nullptr)
	{
		return false;
	}
	if (data < 0)
	{
		return false;
	}
	if (data < node->location)
	{
		cout << ".";
		return find(node->left, data);
	}
	if (data > node->location)
	{
		cout << "-";
		return find(node->right, data);
	}
	return true;
}

// inOrder Traversal Function
void BST::inOrder(Node* node, ostream& os)
{
	if (node == nullptr)
	{
		return;
	}
	inOrder(node->left, os);
	os << node->data << " ";
	inOrder(node->right, os);
}

// preOrder Traversal Function
void BST::preOrder(Node* node, ostream& os)
{
	if (node == nullptr)
	{
		return;
	}
	os << node->data << " ";
	preOrder(node->left, os);
	preOrder(node->right, os);
}

// postOrder Traversal Function
void BST::postOrder(Node* node, ostream& os)
{
	if (node == nullptr)
	{
		return;
	}
	postOrder(node->left, os);
	postOrder(node->right, os);
	os << node->data << " ";
}

// Destroy Function
void BST::destroy(Node*& node)
{
	if (node == nullptr)
	{
		return;
	}
	destroy(node->left);
	destroy(node->right);
	delete node;
	node = nullptr;
}

// Degree Function
int Node::degree() const
{
	int degree;
	if (left == nullptr)
	{
		if (right == nullptr)
		{
			degree = 0;
		}
		if (right != nullptr)
		{
			degree = 1;
		}
	}
	if (left != nullptr)
	{
		if (right == nullptr)
		{
			degree = 1;
		}
		if (right != nullptr)
		{
			degree = 2;
		}
		
	}
	return degree;
}