#pragma once
/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a program that implements a Heap and simulates preemptive Process scheduling
*/

#include <iostream>
#include "Process.h"
using namespace std;

// Heap Class
class Heap
{
private:
	Process* heap;
	int size;
	int elements;

	void bubbleUp(int idx);
	void bubbleDown(int idx);
	void swap(int idx1, int idx2);

	void reallocate();


public:

	Heap() : heap(new Process[20]), size(20), elements(0) {}

	void insert(Process task);
	void peek(Process*& top);
	void remove(Process*& task);
	void buildHeap(Process* pile, int size);

	int getElements() { return elements; }
};


