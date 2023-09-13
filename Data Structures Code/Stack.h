#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Implements a stack that stores 4x4 transformation matrices
*/


//Creates the Matrix class
class Matrix
{
public:
	float data[4][4];
	Matrix() : data{ {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} } {};

	bool setValue(int index_x, int _index_y, float value);
	Matrix multiply(Matrix input);
};

// Creates the Node class
class Node
{
public:
	Matrix data;
	Node* next;

	Node() : next(nullptr) {}
	Node(Matrix data) : data(data), next(nullptr) {}
	Node(Matrix data, Node* next) : data(data), next(next) {}
};

// Creates the Stack class
class Stack
{
private:
	Node* top;
public:
	Stack() : top(nullptr) {}
	~Stack();

	void push(Matrix data);
	bool pop(Matrix& data);
	bool peek(Matrix& data);
	bool multiplyStack(Matrix& data);
};