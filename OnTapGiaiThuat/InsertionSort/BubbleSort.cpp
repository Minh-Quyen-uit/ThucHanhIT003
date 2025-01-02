#include "BubbleSort.h"

void BubbleSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void BubbleSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void BubbleSort::Sort()
{
	int i = 0, j = 0;
	for (i; i < this->n; i++) 
		for (j = this->n - 1; j > i; j--) 
			if (this->Arr[j] < this->Arr[j - 1]) 
				this->swapSort(this->Arr[j], this->Arr[j - 1]);
			
}

ostream& operator<< (ostream& os, BubbleSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}