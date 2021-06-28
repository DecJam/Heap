#include "Heap.h"
#include "DynamicArray.h"

// Heap's constructor	
Heap::Heap()
{

}

// Heap's Destructor
Heap::~Heap()
{

}

// Removes a specified value
void Heap::Remove(int value)
{
	m_Data.Remove(value);
}

// Adds a value to the stack
void Heap::Push(int nValue)
{
	// Adds to the array
	m_Data.Add(nValue);

	int currentIndex = Size() - 1;
	int parentIndex = GetParentIndex(currentIndex);
	
	// Sorts the stack so that lower numbers apear first
	while (parentIndex >= 0 && m_Data[parentIndex] > m_Data[currentIndex])
	{
		m_Data[currentIndex] = m_Data[parentIndex];
		m_Data[parentIndex] = nValue;
		currentIndex = parentIndex;
		parentIndex = GetParentIndex(currentIndex);
	}
}

// Prints all values to console
void Heap::Print()
{
	m_Data.PrintAll();
}

// Prints out a value to console
void Heap::Print(int value)
{
	std::cout << value;
}

// Returns the first value and removes it from the array
int Heap::Pop()
{
	if (Size() > 0)
	{
		// Removing the first value 
		int result = m_Data[0];
		m_Data[0] = m_Data[Size() - 1];
		m_Data.RemoveAt(Size()-1);

	
		int parentIndex = 0;
		int child1Index = GetChild1Index(parentIndex);
		int child2Index = GetChild2Index(parentIndex);
		int childIndex;
		int temp;
		
		// If the perant has a child
		while (Exists(child1Index))
		{		
			childIndex = child1Index;

			if (Exists(child2Index))
			{
				if (m_Data[child1Index] > m_Data[child2Index])
				{
					childIndex = child2Index;
				}
			}
			
			// If needed to swap, swaps
			if (m_Data[childIndex] < m_Data[parentIndex])
			{
				temp = m_Data[childIndex];
				m_Data[childIndex] = m_Data[parentIndex];
				m_Data[parentIndex] = temp; 

				parentIndex = childIndex;
				child1Index = GetChild1Index(parentIndex);
				child2Index = GetChild2Index(parentIndex);
			}

			else
			{
				break;
			}
		}
	}
	
	else
	{
		return - 1;
	}
}

// Returns the top value of the heap
int Heap::Peek()
{
	if (Size() > 0)
	{
		return m_Data[0];
	}

	else
	{
		return -1;
	}
}

// Returns true if the value exists
bool Heap::Exists(int index)
{
	return (index < Size());
}

// Returns the size of the heap
int Heap::Size()
{
	return m_Data.GetSize();
}

// Clears the heap
void Heap::Clear()
{
	m_Data.Clear();
}

// Returns the parent index
int Heap::GetParentIndex(int nIndex)
{
	return (nIndex-1) / 2;
}

// Returns the left child's index
int Heap::GetChild1Index(int nIndex)
{
	int result = (2 * nIndex) + 1;
	if (result < Size())
	{
		return result;
	}

	else
	{
		return nIndex;
	}
}

// Returns the right childs index
int Heap::GetChild2Index(int nIndex)
{
	int result =  (2 * nIndex) + 2;
	if (result < Size())
	{
		return result;
	}

	else
	{
		return nIndex;
	}
}
