/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Writing a tokenizer class to be used in future programs
*/

#include "Tokenizer.h"

#include <sstream>
#include <iostream>
#include <string>

using std::stringstream;
using std::string;
using std::istream;
using std::cout;
using std::endl;


int main()
{
	Tokenizer t;


	t.setString("3.02 this is test number 1");

	int i;
	if (t.readInteger(i))
	{
		 cout << "Success." << endl;
	}
	else
	{
		cout << "Test failed. No integer." << endl;
	}

	string s;
	if (t.readWord(s))
	{
		cout << "Success." << endl;
	}
	else
	{
		cout << "Test failed. No word." << endl;
	}

	double d;
	if (t.readDouble(d))
	{
		cout << "Success." << endl;
	}
	else
	{
		cout << "Test failed. No double." << endl;
	}

	string l;
	if (t.readLine(l))
	{
		cout << "Success." << endl;
	}
	else
	{
		cout << "Test failed. No line." << endl;
	}

	return 0;
}