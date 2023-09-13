/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a program that implements a Heap and simulates preemptive task scheduling
*/

#include <iostream>
#include <vector>
#include <sstream>
#include "Simulation.h"
using namespace std;

// Search/Find Function
bool Simulation::find(string task) {

	for (int i = 0; i < waiting.size(); i++) {
		if (waiting[i].getName() == task) {
			return true;
		}
	}

	return false;
}

// Remove Function
bool Simulation::remove(string task) {
	int idx = 0;
	for (int i = 0; i < waiting.size(); i++) {
		if (waiting[i].getName() == task) {
			idx = i;
		}
	}
	// Erase
	waiting.erase(waiting.begin() + idx);

	return true;
}

// Clear Function
void Simulation::clear() {

	waiting.clear();
}

void Simulation::display() {
	cout << "Tasks yet to be scheduled" << endl;
	for (int i = 0; i < waiting.size(); i++) {
		cout << '\t';
		waiting[i].printProcess();
	}
}

// Step Function
int Simulation::step(int step) {
	Process* tmp;

	// Step 1
	for (int i = 0; i < step; i++) {

		if (h.getElements() == 0 && waiting.size() == 0) {
			return -1; 
		}

		cout << "Time Step    = " << time << endl;

		int j = 0;

		// Step 2
		while (j < waiting.size()) {

			if (waiting[j].getArrival() == time) {
				Process tmp1 = waiting[j];
				h.insert(tmp1);

				remove(waiting[j].getName());
				Process* tmp2 = &tmp1;

				cout << "               added "; tmp2->printProcess();

			}

			else {
				j++;
			}
		}

		// Step 4
		h.peek(tmp);
		tmp->insertElapsed();

		if (tmp->getElapsed() > tmp->getLength()) {

			cout << "               " << tmp->getName() << " has finished" << endl;

			tmp->resetProcess();
			done.push_back(*tmp);
			h.remove(tmp);


			if (tmp != nullptr) {
				tmp->insertElapsed();
			}

			if (h.getElements() == 0 && waiting.size() == 0) {
				return -1;
			}

		}
		// Step 2
		if (tmp == nullptr) {
			cout << "Current Task = None " << endl;
		}
		// Output Curret Task
		else {
			cout << "Current Task = "; tmp->printProcess();
		}

		cout << endl;
		// Step 6
		time++;

	}
	return 0;

}

// Reset Function
void Simulation::reset() {
	Process* tmp;
	while (h.getElements() != 0) {
		Process* tmp1;
		h.peek(tmp1);
		waiting.push_back(*tmp1);

		h.remove(tmp);
	}
	for (int i = 0; i < done.size(); i++) {
		tmp = &done.at(i);
		waiting.push_back(*tmp);

	}
	done.clear();
	time = 0;
}
