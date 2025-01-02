#include "BinaryInsertionSort.h"

void BinaryInsertionSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void BinaryInsertionSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void BinaryInsertionSort::Sort()
{
	int i = 1, j = 0, l = 0, r = 0, m = 0, x = 0;
	while (i < this->n) {
		x = this->Arr[i];
		l = 0;
		r = i - 1;
		while (l <= r)
		{
			m = (l + r) / 2;
			if (x < this->Arr[m])
				r = m - 1;
			else 
				l = m + 1;
		}
		j = i - 1;
		while (j >= l)
		{
			this->Arr[j + 1] = this->Arr[j];
			j--;
		}
		this->Arr[l] = x;
		i++;
	}

}

ostream& operator<< (ostream& os, BinaryInsertionSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}