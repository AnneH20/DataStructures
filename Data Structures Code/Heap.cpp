/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Creates a program that implements a Heap and simulates preemptive task scheduling
*/

#include <iostream>
#include "Heap.h"
#include "Process.h"
using namespace std;

// BubbleUp Function
void Heap::bubbleUp(int idx) {
	if (idx == 0) return;

	int parent = (idx - 1) / 2;

	if (heap[idx].getPriority() < heap[parent].getPriority()) {
		swap(idx, parent);
		bubbleUp(parent);
	}

}

// BubbleDown Function
void Heap::bubbleDown(int idx) {

	int min = idx;
	int left = 2 * idx + 1;
	int right = left + 1;

	if (left > elements - 1) return;
	if (right > elements - 1) { min = left; }

	else if (heap[left].getPriority() < heap[right].getPriority()) {
		min = left;
	}

	else {
		min = right;
	}

	if (min != idx) {
		swap(idx, min);
		bubbleDown(min);
	}
}

// Reallocate Function
void Heap::reallocate() {

	Process* old = heap;

	size *= 2;
	heap = new Process[size];

	for (int i = 0; i < elements; i++) {
		heap[i] = old[i];
	}

	delete[] old;
}

// Swap Function
void Heap::swap(int idx1, int idx2) {

	Process tmp1 = heap[idx1];
	Process tmp2 = heap[idx2];

	heap[idx1] = tmp2;
	heap[idx2] = tmp1;

}

// Insert Function
void Heap::insert(Process task) {
	heap[elements] = task;

	bubbleUp(elements);
	elements++;
}

// Remove Function
void Heap::remove(Process*& task) {
	if (elements == 0) return;

	elements--;

	Process* tmp = &heap[0];

	task = tmp;
	heap[0] = heap[elements];
	bubbleDown(0);

}

// BuildHeap Function
void Heap::buildHeap(Process* pile, int size) {

	for (int idx = size / 2; idx >= 0; idx--) {
		bubbleDown(idx);
	}

}

// Peek Function
void Heap::peek(Process*& top) {

	if (elements == 0) {
		top = nullptr;
		return;
	}

	Process* tmp = &heap[0];

	top = tmp;

}