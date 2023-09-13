#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a BST that translates a word into Morse Code
*/

#include <iostream>
using namespace std;

// Class for Node
class Node
{
public:
	char data;
	int location;
	Node* left;
	Node* right;
	Node() : data (0), location(0), left(nullptr), right(nullptr) {}
	Node(char data, int location) : data(data), location(location), left(nullptr), right(nullptr) {}
	int degree() const;
};