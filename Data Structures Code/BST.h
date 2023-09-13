#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a BST that translates a word into Morse Code
*/
#include <iostream>
#include "Node.h"
#include "Morse.h"
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a BST that translates a word into Morse Code
*/

using namespace std;

// Class for BST
class BST
{ 
private:
	Node* root; 
	bool insert(Node*& node, char data, int location); 
	bool remove(Node*& node, char data); 
	bool findlocation(Node* node, char data, int& location); 
	bool find(Node* node, int data);
	void inOrder(Node* node, ostream& os); 
	void preOrder(Node* node, ostream& os); 
	void postOrder(Node* node, ostream& os); 
	void destroy(Node*& node);
public:
	BST() : root(nullptr) {}
	~BST(); 
	bool insert(char data, int location) { insert(root, data, location); return true; }
	bool remove(char data) { remove(root, data); ; return true; }
	int findlocation (char data) { int x; findlocation(root, data, x); return x; }
	void inOrder(ostream& os) { inOrder(root, os); }
	void preOrder(ostream& os) { preOrder(root, os); }
	void postOrder(ostream& os) { postOrder(root, os); }
	void destroy() { destroy(root); }
	bool find(int data) { if (find(root, data)) { return true; } else { return false; } }
};