/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Implements a stack that stores 4x4 transformation matrices
*/

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <math.h>

#include "Stack.h"

using std::istream;
using std::stringstream;
using std::string;

// Stack deconstructor
Stack::~Stack()
{
	Node* tmp = top;
	while (tmp != nullptr)
	{
		top = tmp->next;
		delete tmp;
		tmp = top;
	}
}

// Creates a new node and stores the matrix in that node and pushes it onto the stack
void Stack::push(Matrix data)
{
	Node* tmp = new Node(data);
	tmp->next = top;
	top = tmp;
}

// Removes the node from the top of the stack
bool Stack::pop(Matrix& data)
{
	Node* tmp = top;
	if (top == nullptr)
	{
		return false;
	}
	top = top->next;
	delete tmp;
	return true;
}

// Copies the matrix from the node on top of the stack
bool Stack::peek(Matrix& data)
{
	if (top == nullptr)
	{
		return false;
	}
	data = top->data;
	return true;
}

// Multiplies the identity matrix by the top of the stack and pops the stack until the stack is empty
bool Stack::multiplyStack(Matrix& data)
{
	Matrix tmp;
	while (top != nullptr)
	{
		Matrix data;
		peek(data);
		tmp = tmp.multiply(data);
		pop(data);

	}
	data = tmp;
	return true;
};

// Allows the user to change a value at a given point in the matrix
bool Matrix::setValue(int index_x, int index_y, float value)
{
	if (-1 < index_x && index_x < 4)
	{
		if (-1 < index_y && index_y < 4)
		{
			data[index_x][index_y] = value;
			return true;
		}
	}
	return false;
}

// Multiplies two matrices together
Matrix Matrix::multiply(Matrix input)
{
	Matrix m;
	float num;
	int i, j, k;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			num = 0.0;
			for (k = 0; k < 4; k++)
			{
				num += data[i][k] * input.data[k][j];
			}
			m.setValue(i, j, num);
		}
	}
	return m;
}