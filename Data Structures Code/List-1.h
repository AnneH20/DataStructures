/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Write a text-based interface that will use
commands to navigate a doubly linked list
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

using std::istream;
using std::stringstream;
using std::string;

class Node
{
public:
	string event;
	int duration;
	Node* next;
	Node* prev;

	Node() : event(" "), duration(0), next(nullptr), prev(nullptr) {}


	Node(string event, int duration) : event(event), duration(duration), next(nullptr), prev(nullptr) {}
	Node(string event, int duration, Node* next, Node* prev) : event(event), duration(duration), next(next), prev(prev) {}
};


class doublyLinkedList
{
private:
	Node* head;
	Node* tail;

public:
	doublyLinkedList() : head(nullptr), tail(nullptr) {}
	~doublyLinkedList();


	void append(string event, int duration);
	void prepend(string event, int duration);
	bool search(string event);
	bool remove(string event);
	bool insertBefore(string event, int duration, string event2);
	bool insertAfter(string event, int duration, string event2);
	void displayUntil(ostream& os, int duration);
	int length();
	void display(ostream& os);
	void clear();
	friend ostream &operator<<(ostream &os, doublyLinkedList &right);
};