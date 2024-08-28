#pragma once
#include <chrono>
#include "Key.h"

#define STEADY_CLOCK_DURATION std::chrono::time_point<std::chrono::steady_clock, std::chrono::steady_clock::duration>

// class Key; DOESN'T WORK 

// Forward Declaration only works if used as pointer
// in this case Key*

// Why? Compiler needs to know size of Key at complile time
// if you just Forward Declare Key, when you compile the header
// file it won't know the size of Key

// If you were to use Key*, compiler knows size of a * is same as int
// so ONLY USE FORWARD DECLARATION FOR POINTERS & DYNAMIC MEMORY

struct Node {
	Key key;
	STEADY_CLOCK_DURATION end_time;
	Node* next;
	Node(Key key_t, STEADY_CLOCK_DURATION end_time_t);
};


class LinkedList
{
	Node* m_head;
	Node* m_tail;
	int m_size;

public:
	LinkedList();
	~LinkedList();


	void addNode(Key& key_t, STEADY_CLOCK_DURATION end_time_t );
	void popNode();
	Node* getHead();

};


