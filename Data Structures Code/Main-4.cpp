/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a BST that translates a word into Morse Code
*/

#include "Tokenizer.h"
#include "Morse.h"
#include "Node.h"
#include "BST.h"
#include <fstream>
#include <cmath>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

bool processText(istream& is, BST &b, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// add string string ... concatenate two strings
	// add double double ... sum two integers
	// load file ... loads a file containing supported commands
	string line;
	string command;
	string arg1, arg2;
	double darg1, darg2, darg3;
	int depth;
	char carg1;
	Tokenizer tkn;
	Morse morseObject;

	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << ">> "; }

		getline(is, line);
		tkn.setString(line);

		// Exit Command
		tkn.readWord(command);
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}

		// Load Command
		if (command == "load")
		{
			// load expects a filename .. so read one more word
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue; // skip back to the top of the read loop
			}
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				status = processText(fin, b, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}

		// Construct Tree Command - Creates BST
		if (command == "constructTree")
		{
			if (tkn.readInteger(depth))
			{
				int arrCount = 0;
				for (int rowCount = 0; rowCount <= depth; rowCount++)
				{
					int rowElementCount = pow(2, rowCount);
					int rowElement = pow(2, (depth - rowCount));
					int rowElementCounter = pow(2, (depth - rowCount + 1));
					for (int j = 0; j < rowElementCount; j++, rowElement += rowElementCounter) {
						b.insert(morseObject.morseTree[arrCount], rowElement);
						arrCount++;
					}
				}
			}
			cout << "Tree constructed with depth: " << depth << endl;
			continue;
		}

		// Preorder Traversal Command - Prints the tree via Preorder Traversal
		if (command == "preOrderTraversal")
		{
			cout << "preOrder: ";
			b.preOrder(cout);
			cout << endl;
			continue;
		}

		// Inorder Traversal Command - Prints the tree via Inorder Traversal
		if (command == "inOrderTraversal")
		{
			cout << "inOrder: ";
			b.inOrder(cout);
			cout << endl;
			continue;
		}

		// Postorder Traversal Command - Print the tree via Postorder Traversal
		if (command == "postOrderTraversal")
		{
			cout << "postOrder: ";
			b.postOrder(cout);
			cout << endl;
			continue;
		}

		// Convert String Command - Converts a string to Morse Code
		if (command == "convertString")
		{
			string a;
			if (tkn.readLine(arg1))
			{
				a = arg1;
				char* char_arr;
				char_arr = &a[0];
				for (int i = 0; i < a.length(); i++)
				{
					int x = b.findlocation(char_arr[i]);
					b.find(x);
					cout << endl;
				}
				continue;
			}
		}

		// Clear Command - Clears the entire tree
		if (command == "clear")
		{
			b.~BST();
			cout << "Success: Tree deleted." << endl;
			continue;
		}
	}
}


int main()
{
	BST b;
	processText(cin, b);
	return 0;
}