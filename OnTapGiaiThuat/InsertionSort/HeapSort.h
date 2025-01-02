#pragma once
#include <iostream>
using namespace std;

class HeapSort
{
private:
	int* Arr;
	int n;
public:
	void addArray(int[], int);
	void swapSort(int&, int&);
	void Shift(int, int);
	void CreateHeap();
	void Sort();

	friend ostream& operator<< (ostream&, HeapSort);
};

