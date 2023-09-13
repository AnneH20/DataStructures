#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a program that implements a Heap and simulates preemptive task scheduling
*/

using namespace std;

// Process Class
class Process
{
public:

private:
	string task;
	int priority;
	int length;
	int elapsed;
	int arrival;

public:
	Process() : task(), priority(), length(), elapsed(), arrival() {}
	Process(string task, int priority, int length, int arrival) : task(task), priority(priority), length(length), elapsed(0), arrival(arrival) {}

	// Getters
	string getName() { return task; }
	int getPriority() { return priority; }
	int getLength() { return length; }
	int getElapsed() { return elapsed; }
	int getArrival() { return arrival; }

	// Setters
	void setPriority(int priority) { priority = this->priority; }
	void setLength(int length) { length = this->length; }
	void insertElapsed() { elapsed++; }
	void setArrival(int arrival) { arrival = this->arrival; }
	void resetProcess() { elapsed = 0; }

	// Print Statement
	void printProcess() {
		cout << task << " @ " << priority << " for " << elapsed << " out of " << length << " arriving at " << arrival << endl;
	}
};