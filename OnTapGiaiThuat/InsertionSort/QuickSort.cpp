#include "QuickSort.h"

void QuickSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void QuickSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void QuickSort::Sort(int l, int r)
{
	
	int i = l, j = r;
	int pivot = (l + r) / 2;
	int x = this->Arr[pivot];
	do
	{
		while (x > this->Arr[i]) i++;
		while (x < this->Arr[j]) j--;
		if (i <= j)
		{
			this->swapSort(this->Arr[i], this->Arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > l) 
		this->Sort(l, j);
	if (i < r)
		this->Sort(i, r);

}

ostream& operator<< (ostream& os, QuickSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}