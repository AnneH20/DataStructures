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

class Morse
{
public:
	char morseTree[63];
	Morse() : morseTree{
		// 1st Row (blank start)
		'\0',
		// 2nd Row
		'E',
		'T',
		// 3rd Row
		'I', 'A',
		'N', 'M',
		// 4th Row
		'S', 'U', 'R', 'W',
		'D', 'K', 'G', 'O',
		// 5th Row
		'H', 'V', 'F', '\0', 'L', '\0', 'P', 'J',
		'B', 'X', 'C', 'Y', 'Z', 'Q', '\0', '\0',
		// 6th Row
		'5', '4', '\0', '3', '\0', '\0', '\0', '2', '\0', '\0', '+', '\0', '\0;', '\0', '\0', '1',
		'6', '=', '/', '\0', '\0', '\0', '\0', '\0', '7', '\0', '\0', '\0', '8', '\0', '9', '0' } {};
};