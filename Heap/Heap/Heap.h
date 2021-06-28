#pragma once
#include "DynamicArray.h"

class Heap
{
public:
	Heap();
	~Heap();
	
	void Remove(int value);
	void Push(int nValue);
	void Print();
	void Print(int value);
	int Pop();
	int Peek();
	bool Exists(int index);
	int Size();
	void Clear();

private:
	int GetParentIndex(int nIndex);
	int GetChild1Index(int nIndex);
	int GetChild2Index(int nIndex);

	DynamicArray<int> m_Data;
};