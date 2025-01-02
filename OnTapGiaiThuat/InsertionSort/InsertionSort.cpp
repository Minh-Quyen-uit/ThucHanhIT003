#include "InsertionSort.h"

void InsertionSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void InsertionSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void InsertionSort::Sort() 
{
	int i = 1, x = 0, pos = 0;
	
	while (i < n) 
	{
		x = this->Arr[i];
		pos = i - 1;

		while ((pos >= 0) && (this->Arr[pos] > x))
		{
			this->Arr[pos + 1] = this->Arr[pos];
			pos--;
		}

		this->Arr[pos + 1] = x;
		i++;
	}
}

ostream& operator<< (ostream& os, InsertionSort x)
{
	for (int i = 0; i < x.n; i++)
		os << x.Arr[i] << " ";
	
	os << "\n";
	return os;
}