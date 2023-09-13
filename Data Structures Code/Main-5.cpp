/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a program that implements a Heap and simulates preemptive task scheduling
*/

#include "Tokenizer.h"
#include "Process.h"
#include "Simulation.h"
#include "Heap.h"
#include <fstream>

using namespace std;

string mode = "scheduling";


bool processText(istream& is, Simulation& sim, bool interactive = true)
{
	// implement support for 
	// exit ... exit the program
	// add string string ... concatenate two strings
	// add double double ... sum two integers
	// load file ... loads a file containing supported commands
	string line;
	string command;
	string arg1, arg2;
	int iarg1, iarg2, iarg3;
	Tokenizer tkn;

	while (true)
	{
		if (!interactive)
		{
			if (is.eof()) return true;
		}
		else { cout << mode << ">> "; }

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
				status = processText(fin, sim, false);
			}
			else { cout << "Failed to open the file" << endl; }
			fin.close();
			if (!status) return false;
		}

		// Simulation Mode
		if (command == "simulate")
		{
			mode = "simulation";
			cout << "Entered " << mode << " mode" << endl;
			continue;
		}
		
		// Scheduling Mode
		if (command == "schedule")
		{
			mode = "scheduling";

			sim.reset(); //move tasks to vector
			sim.clear(); //clear vector

			cout << "Entered " << mode << " mode" << endl;
			continue;
		}

		// Display Command
		if (command == "display")
		{
			if (mode == "simulation") {

				cout << "Next  Step:    " << sim.getTime() << endl;

				Process* tmp;
				cout << "Current Task: ";
				sim.getHeap().peek(tmp);

				if (tmp == nullptr) { //if no tasks, print no current task
					cout << "None" << endl;
					sim.display();
					continue;
				}
				else {
					tmp->printProcess();
					sim.display();
					continue;
				}

			}
			else {
				sim.display();
				continue;
			}
		}

		// Clear Command
		if (command == "clear")
		{
			if (mode != "scheduling") {
				cout << "That command is not valid during simulation" << endl;
				continue;
			}

			sim.clear();
			cout << "Schedule cleared" << endl;
			continue;
		}

		// Remove Command
		if (command == "remove")
		{
			if (mode != "scheduling") {
				cout << "That command is not valid during simulation" << endl;
				continue;
			}
			if (tkn.readWord(arg1))
			{
				if (!sim.find(arg1)) {
					cout << arg1 << " doesn't exist" << endl;
					continue;
				}

				sim.remove(arg1);
				cout << arg1 << " has been removed from scheduling" << endl;
				continue;
			}
		}

		// Register Command
		if (command == "register")
		{
			if (mode != "scheduling") {
				cout << "That command is not valid during simulation" << endl;
				continue;
			}
			if (tkn.readWord(arg1))
			{
				if (tkn.readInteger(iarg1))
				{
					if (tkn.readInteger(iarg2))
					{
						if (tkn.readInteger(iarg3))
						{
							if (sim.find(arg1)) {
								cout << arg1 << " has already been registered. Remove it first" << endl;
								continue;
							}

							if (iarg1 > 100 || iarg1 < 0) {
								cout << "Failed to register! Priority must be between 1 - 100" << endl;
								continue;
							}

							if (iarg2 <= 0) { //??
								cout << "Failed to register! Length must be be positive" << endl;
								continue;
							}

							if (iarg3 < 0) { //??
								cout << "Failed to register! Arrival time cannot be negative" << endl;
								continue;
							}

							Process* newtask = new Process(arg1, iarg1, iarg2, iarg3);
							sim.insert(newtask);

							cout << arg1 << " registered" << endl;

							continue;
						}
					}
				}
			}
		}

		// Step Commands
		if (command == "step")
		{
			if (mode != "simulation") {
				cout << "That command is not valid during scheduling" << endl;
				continue;
			}
			int timestep = 0;
			if (tkn.readInteger(iarg1)) {
				sim.step(iarg1);
			}
			else
				sim.step(1);
			continue;
		}

		// Run Commands
		if (command == "run")
		{
			if (mode != "simulation") {
				cout << "That command is not valid during scheduling" << endl;
				continue;
			}
			else
				while (sim.step(1) != -1);
		}
		if (command == "runTil")
		{
			if (tkn.readInteger(iarg1))
			{
				int steps = iarg1 - sim.getTime() + 1;
				sim.step(steps);
			}
			continue;
					
		}

		// Reset Commands
		if (command == "reset")
		{
			if (mode != "simulation") {
				cout << "That command is not valid during scheduling" << endl;
				cout << endl;
			}

			sim.reset();
			cout << "Simulation reset" << endl;
			continue;
		}
	}
}





int main()
{
	Simulation sim;

	processText(cin, sim);
	return 0;

}