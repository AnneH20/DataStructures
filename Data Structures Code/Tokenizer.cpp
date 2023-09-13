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



bool Tokenizer::readInteger(int& val)
{
	if (isEmpty())
	{
		return false;
	}
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readDouble(double& val)
{
	if (isEmpty())
	{
		return false;
	}
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}
bool Tokenizer::readLine(string& line)
{
	if (isEmpty())
	{
		return false;
	}
	try
	{
		getline(std::cin, line);
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}

bool Tokenizer::readWord(string& val)
{
	if (isEmpty())
	{
		return false;
	}
	try
	{
		ss >> val;
	}
	catch (std::ios_base::failure)
	{
		ss.clear();
		return false;
	}
	return true;
}


void Tokenizer::setString(const string& str)
{
	ss.str(str);
}


bool Tokenizer::isEmpty()
{
	if (ss.eof()) 
		return true;
	else 
		return false;

}


void Tokenizer::rewind()
{
	ss.seekg(0, ss.beg);
}

void Tokenizer::clear()
{
	setString("");
	ss.setstate(std::ios::eofbit);
}