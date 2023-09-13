/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Implements a stack that stores 4x4 transformation matrices
*/
#define _USE_MATH_DEFINES
#include "Tokenizer.h"
#include "Stack.h"
#include <fstream>
#include <cmath>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

bool processText(istream& is, Stack &s, bool interactive = true)
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
	Tokenizer tkn;

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
				status = processText(fin, s, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}

		// RotateX Command
		if (command == "rotateX")
		{
			if (tkn.readDouble(darg1))
			{
				Matrix m;
				
	
				double sn = sin(darg1 * M_PI / 180);
				double cs = cos(darg1 * M_PI / 180);

				m.setValue(1, 1, cs);
				m.setValue(1, 2, -sn);
				m.setValue(2, 1, sn);
				m.setValue(2, 2, cs);
				
				s.push(m);
			}
			continue;
		}

		// RotateY Command
		if (command == "rotateY")
		{
			if (tkn.readDouble(darg1))
			{
				Matrix m;

				double sn = sin(darg1 * M_PI / 180);
				double cs = cos(darg1 * M_PI / 180);

				m.setValue(0, 0, cs);
				m.setValue(0, 2, sn);
				m.setValue(2, 0, -sn);
				m.setValue(2, 2, cs);

				s.push(m);
			}
			continue;
		}

		// RotateZ Command
		if (command == "rotateZ")
		{
			if (tkn.readDouble(darg1))
			{
				Matrix m;

				double sn = sin(darg1 * M_PI / 180);
				double cs = cos(darg1 * M_PI / 180);

				m.setValue(0, 0, cs);
				m.setValue(0, 1, -sn);
				m.setValue(1, 0, sn);
				m.setValue(1, 1, cs);

				s.push(m);
			}
			continue;
		}

		// Translate Command
		if (command == "translate") //Read 3 doubles
		{
			Matrix m;
			if (tkn.readDouble(darg1))
			{
				m.setValue(3, 0, darg1);
				if (tkn.readDouble(darg2))
				{
					m.setValue(3, 1, darg2);
					if (tkn.readDouble(darg3))
					{
						m.setValue(3, 2, darg3);
					}
					s.push(m);
				}
			}
			continue;
		}

		// Undo Command
		if (command == "undo")
		{
			Matrix m;
			s.pop(m);
			continue;
		}

		// TransformVertex Command
		if (command == "transformVertex")
		{
			tkn.readDouble(darg1);
			tkn.readDouble(darg2);
			tkn.readDouble(darg3);

			Matrix m;
			s.multiplyStack(m);

			float new_x = darg1 * m.data[0][0] + darg2 * m.data[1][0] + darg3 * m.data[2][0] + 1 * m.data[3][0];
			float new_y = darg1 * m.data[0][1] + darg2 * m.data[1][1] + darg3 * m.data[2][1] + 1 * m.data[3][1];
			float new_z = darg1 * m.data[0][2] + darg2 * m.data[1][2] + darg3 * m.data[2][2] + 1 * m.data[3][2];

			cout << "Final Vertex: " << new_x << " " << new_y << " " << new_z << endl;
			continue;
		}
	}
}


int main()
{
	Stack s;
	processText(cin, s);
	return 0;
}