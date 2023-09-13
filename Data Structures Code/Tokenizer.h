#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Writing a tokenizer class to be used in future programs
*/

#include <sstream>
#include <iostream>
#include <string>

using std::stringstream;
using std::string;
using std::istream;


class Tokenizer
{
private:
	stringstream ss;
public:
	Tokenizer()
	{
		ss.exceptions(std::ios::failbit);
	}
	Tokenizer(const string& source)
	{
		ss.str(source);
		ss.exceptions(std::ios::failbit);
	}

	void setString(const string& str);
	bool isEmpty();
	bool readLine(string& line);
	bool readInteger(int& val);
	bool readWord(string& val);
	bool readDouble(double& val);

	void rewind();
	void clear();
};