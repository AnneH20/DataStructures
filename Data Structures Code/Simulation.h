#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a program that implements a Heap and simulates preemptive task scheduling
*/

using namespace std;

// Simulation Class
#include "Heap.h"
#include <iostream>
#include <vector>

// Simulation Class
class Simulation
{
public:
	Simulation() : time(0), h() {}

	// Schedule Functions
	bool find(string task);
	bool remove(string task);
	void insert(Process*& t) { waiting.push_back(*t); }
	void clear();
	int step(int step);

	//Schedule and Simulate Functions
	void display();
	void reset();

	int getTime() { return time; }

	Heap getHeap() { return h; }


private:
	int time = 0;
	Heap h;
	vector<Process> waiting;
	vector<Process> done;

};