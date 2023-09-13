/*
Student Name: Anne Marie Heidebreicht
Student NetID: alh1310
Compiler Used: Visual Studio
Program Description:
Write a text-based interface that will use
commands to navigate a doubly linked list
*/

#include "List.h"
#include "Tokenizer.h"

#include <iostream>
#include <sstream>
#include <string>

using std::istream;
using std::stringstream;
using std::string;

// Append Method - Adds event to bottom of the list
void doublyLinkedList::append(string event, int duration)
{
	Node* tmp = new Node(event, duration);
	tmp->prev = tail;
	if (head == nullptr)
	{
		head = tmp;
	}
	else
	{
		tail->next = tmp;
	}
	tail = tmp;
}

// Prepend Method - Adds event to the top of the list
void doublyLinkedList::prepend(string event, int duration)
{
	Node* tmp = new Node(event, duration);
	tmp->next = head;
	if (head == nullptr)
	{
		tail = tmp;
	}
	else
	{
		head->prev = tmp;
	}
	head = tmp;
}

// Search Method - Searches through the list for a specfic event
bool doublyLinkedList::search(string event)
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->event == event)
		{
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

// Remove Method - Removes a specified event from the list
bool doublyLinkedList::remove(string event)
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->event == event)
		{
			if (tmp->prev != nullptr)
			{
				tmp->prev->next = tmp->next;
			}
			if (tmp->next != nullptr)
			{
				tmp->next->prev = tmp->prev;
			}
			if (tmp == head)
			{
				head = tmp->next;
			}
			if (tmp == tail)
			{
				tail = tmp->prev;
			}
			delete tmp;
			return true;
		}

		tmp = tmp->next;
	}
	return false;
}

// Insert Before Method - Insert an event before another event in the list
bool doublyLinkedList::insertBefore(string event, int duration, string event2)
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		if (tmp->event == event2)
		{
			Node* newnode = new Node(event, duration);
			newnode->next = tmp;
			newnode->prev = tmp->prev;

			if (tmp == head)
			{
				head = newnode;
			}
			else
			{
				tmp->prev->next = newnode;
			}
			tmp->prev = newnode;
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

// Insert After Method - Inserts an event after another event in the list
bool doublyLinkedList::insertAfter(string event, int duration, string event2)
{
	Node* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->event == event2)
		{
			Node* newnode = new Node(event, duration);
			newnode->prev = tmp;
			newnode->next = tmp->next;

			if (tmp == tail)
			{
				tail = newnode;
			}
			else
			{
				tmp->next->prev = newnode;
			}
			tmp->next = newnode;
			return true;
		}

		tmp = tmp->next;
	}
	return false;
}

// Length Method - Outputs the elapsed time in the list
int doublyLinkedList::length()
{
	Node* tmp = head;
	int sum = 0;
	while (tmp != nullptr) 
	{
		sum += tmp->duration;
		tmp = tmp->next;
	}
	return sum;
}

// Display Until Method - Displays the list before a given elasped time
void doublyLinkedList::displayUntil(ostream &os, int duration)
{
	Node* tmp = head;
	int sum = 0;
	while (tmp != nullptr)
	{
		if (sum < duration)
		{
			os << "Event: " << tmp->event << ", Duration: " << tmp->duration << endl;
		}
		sum += tmp->duration;
		tmp = tmp->next;
	}
}

// Display Method - Outputs the contents of the list
void doublyLinkedList::display(ostream& os)
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		os << "Event: " << tmp->event << ", Duration: " << tmp->duration << endl;
		tmp = tmp->next;
	}
}

doublyLinkedList::~doublyLinkedList()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = head->next;
		delete tmp;
		tmp = head;
	}
	tail = nullptr;
}

ostream &operator<<(ostream &os, doublyLinkedList &right)
{
	right.display(os);
	return os;
}

// Clear Method - Clears the entire contents of the list
void doublyLinkedList::clear()
{
	Node* tmp = head;

	while (head != NULL) 
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}