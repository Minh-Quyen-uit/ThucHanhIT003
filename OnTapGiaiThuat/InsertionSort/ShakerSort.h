#pragma once
#include <iostream>
using namespace std;

class ShakerSort
{
private:
	int* Arr;
	int n;
public:
	void addArray(int[], int);
	void swapSort(int&, int&);
	void Sort();

	friend ostream& operator<< (ostream&, ShakerSort);
};

