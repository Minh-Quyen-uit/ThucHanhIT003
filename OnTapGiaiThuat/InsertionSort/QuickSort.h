#pragma once
#include <iostream>
using namespace std;

class QuickSort
{
private:
	int* Arr;
	int n;
public:
	void addArray(int[], int);
	void swapSort(int&, int&);
	void Sort(int, int);

	friend ostream& operator<< (ostream&, QuickSort);
};

