#include "InterchangeSort.h"

void InterchangeSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void InterchangeSort::swapSort(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void InterchangeSort::Sort()
{
	int i = 0, j = 0;
	for (i; i < this->n - 1; i++) 
		for (j = i + 1; j < this->n; j++)
			if (this->Arr[j] < this->Arr[i]) 
				this->swapSort(this->Arr[i], this->Arr[j]);
}

ostream& operator<< (ostream& os, InterchangeSort x)
{
	for (int i = 0; i < x.n; i++) 
		os << x.Arr[i] << " ";
	os << "\n";
	return os;
}