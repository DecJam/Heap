#pragma once
#include "DynamicArray.h"

class Heap
{
public:
	// Heaps's constructor
	Heap();

	// Heaps destructor
	~Heap();
	
	// Adds a node to the top of the heap
	void Push(int nValue);

	// Prints all the nodes out in order
	void Print();

	// Prints a specific node
	void Print(int value);

	// Returns and removes the top node
	int Pop();

	// Returns the top node
	int Peek();

	// Returns if the node exists
	bool Exists(int index);

	// Returns the size of the heap
	int Size();

	// Clears the heap
	void Clear();

private:
	// Returns the parent index
	int GetParentIndex(int nIndex);

	// Returns the child index
	int GetChild1Index(int nIndex);

	// Returns the child index
	int GetChild2Index(int nIndex);

	// The heaps storage
	DynamicArray<int> m_Data;
};