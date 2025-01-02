#include "SelectionSort.h"

void SelectionSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void SelectionSort::swapSort(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}

void SelectionSort::Sort()
{
	int i = 0, j = 0, min = 0;
	for (i; i < this->n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < this->n; j++) 
			if (this->Arr[min] > this->Arr[j])
				min = j;

		this->swapSort(this->Arr[i], this->Arr[min]);
	}
}

ostream& operator<< (ostream& os, SelectionSort x)
{
	for (int i = 0; i < x.n; i++) 
		os << x.Arr[i] << " ";

	os << "\n";
	return os;
}