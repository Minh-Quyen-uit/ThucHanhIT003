#pragma once
#include <iostream>
using namespace std;

class MergeSort
{
private:
	int* Arr;
	int n;
public:
	void addArray(int[], int);
	void swapSort(int&, int&);
	int Min(int, int);
	void Distribute(int, int&, int&, int);
	void Merge(int, int, int);
	void Sort();

	friend ostream& operator<< (ostream&, MergeSort);
};

