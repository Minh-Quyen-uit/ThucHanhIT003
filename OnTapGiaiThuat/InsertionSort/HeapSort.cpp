#include "HeapSort.h"

void HeapSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void HeapSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void HeapSort::Shift(int l, int r) 
{
	int x, i, j;
	i = l;
	j = 2 * i + 1;
	x = this->Arr[i];
	while (j <= r)
	{
		if (j < r)
			if (this->Arr[j] < this->Arr[j + 1])
				j++;
		if (this->Arr[j] <= x)
			return;
		else
		{
			this->Arr[i] = this->Arr[j];
			this->Arr[j] = x;
			i = j;
			j = 2 * i + 1;
			x = this->Arr[i];
		}
	}
}

void HeapSort::CreateHeap()
{
	int l;
	l = this->n / 2 - 1;
	while (l >= 0)
	{
		this->Shift(l, this->n-1);
		l--;
	}
}

void HeapSort::Sort()
{
	int r;
	this->CreateHeap();
	r = n - 1;
	while (r > 0)
	{
		this->swapSort(this->Arr[0], this->Arr[r]);
		r--;
		if (r > 0)
			this->Shift(0, r);
	}
}

ostream& operator<< (ostream& os, HeapSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}