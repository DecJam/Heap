#include <iostream>
#include "Heap.h"

int main()
{
	Heap heap;

	heap.Push(5);
	heap.Push(6);
	heap.Push(20);
	heap.Push(7);
	heap.Push(23);
	heap.Push(2);
	heap.Print();

	std::cout << "Size: ";
	heap.Print(heap.Size());
	std::cout << std::endl;

	std::cout << "Peak: ";
	heap.Print(heap.Peek());
	std::cout << std::endl;

	std::cout << std::endl;
	heap.Pop();
	heap.Print();

	std::cout << "Size: ";
	heap.Print(heap.Size());
	std::cout << std::endl;

	std::cout << "Peak: ";
	heap.Print(heap.Peek());
	std::cout << std::endl;

	return 0;
}