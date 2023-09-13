/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Write a text-based interface that will use
commands to navigate a doubly linked list
*/

#include "Tokenizer.h"
#include "List.h"
#include <fstream>

using std::ifstream;
using std::cin;
using std::cout;
using std::endl;


bool processText(istream& is, bool interactive = true)
{
	doublyLinkedList n;
	string line;
	string command;
	string arg1, arg2;
	string event;
	int duration;
	string event2;
	string ba;
	Tokenizer tkn;

	cout << "Commands:" << endl;
	cout << "---> append <event> <time>" << endl;
	cout << "---> prepend <event> <time>" << endl;
	cout << "---> insert <event> <time> before <location>" << endl;
	cout << "---> insert <event> <time> after <location>" << endl;
	cout << "---> length" << endl;
	cout << "---> display" << endl;
	cout << "---> display until <time>" << endl;
	cout << "---> find <event>" << endl;
	cout << "---> remove <event>" << endl;
	cout << "---> clear" << endl;
	cout << "---> load <file>" << endl;
	
	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else
		{
			cout << ">> "; 
		}

		getline(is, line);
		tkn.setString(line);

		tkn.readWord(command);
		// Exit command
		if (command == "exit")
		{
			cout << "Exiting ...." << endl;
			return false;
		}
		// Load command
		if (command == "load")
		{
			if (!tkn.readWord(arg1)) {
				cout << "Missing file name" << endl;
				continue;
			}
			ifstream fin;
			bool status = true;
			fin.open(arg1);
			if (fin.is_open())
			{
				status = processText(fin, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}
		// Prepend command
		if (command == "prepend")
		{
			if (tkn.readWord(event))
			{
				if (tkn.readInteger(duration))
				{
					n.prepend(event, duration);
					cout << "Prepend " << "Event: " << event << " Duration: " << duration << " successful." << endl;
					continue;
				}
			}
		}
		// Insert commands
		if (command == "insert")
		{
			if (tkn.readWord(event))
			{
				if (tkn.readInteger(duration))
				{
					if (tkn.readWord(ba))
					{
						if (ba == "before")
						{
							if (tkn.readWord(event2))
							{
								if (n.insertBefore(event, duration, event2) == true)
								{
									cout << "Insert " << event << " before " << event2 << " successful." << endl;
									continue;
								}
								else
								{
									cout << "ERROR: Cannot insert before an event not in list." << endl;
									continue;
								}
							}
						}
						else if (ba == "after")
						{
							if (tkn.readWord(event2))
							{
								if (n.insertAfter(event, duration, event2) == true)
								{
									cout << "Insert " << event << " after " << event2 << " successful." << endl;
									continue;
								}
								else
								{
									cout << "ERROR: Cannot insert after an event not in list." << endl;
									continue;
								}
							}
						}
						else
						{
							cout << "ERROR: Must insert before or insert after." << endl;
							continue;
						}
					}
				}
			}
		}
		// Append command
		if (command == "append")
		{
			if (tkn.readWord(event))
			{
				if (tkn.readInteger(duration))
				{
					n.append(event, duration);
					cout << "Append " << "Event: " << event << " Duration: " << duration << " successful." << endl;
					continue;
				}
			}
		}
		// Find command
		if (command == "find")
		{
			if (tkn.readWord(event))
			{
				if (n.search(event) == true)
				{
					cout << "Found! Event: " << event << ", " << "Duration: " << duration << endl;
					continue;
				}
				if (n.search(event) == false)
				{
					cout << "ERROR: Event not found in list." << endl;
					continue;
				}
			}
		}
		// Remove command
		if (command == "remove")
		{
			if (tkn.readWord(event))
			{
				if (n.remove(event) != NULL)
				{
					cout << event << " successfully removed." << endl;
					continue;
				}
				else if (n.remove(event) == NULL)
				{
					cout << "ERROR: Event not in list." << endl;
					continue;
				}
			}
		}
		// Clear command
		if (command == "clear")
		{
			n.clear();
			cout << "Events successfully cleared." << endl;
			continue;
		}
		// Display command
		if (command == "display")
		{
			n.display(cout);
			continue;
		}
		// Display Until command
		if (command == "display until")
		{
			if (tkn.readInteger(duration))
			{
				n.displayUntil(cout, duration);
				continue;
			}
		}
		// Length command
		if (command == "length")
		{
			cout << "The total duration of the events is: " << n.length() << endl;
			continue;
		}
	}
}
	
// Calls the menu commands
int main()
{
	processText(cin);
}