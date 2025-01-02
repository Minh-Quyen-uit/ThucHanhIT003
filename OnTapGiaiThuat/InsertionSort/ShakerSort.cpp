#include "ShakerSort.h"

void ShakerSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void ShakerSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void ShakerSort::Sort() 
{
	int l = 0, r = this->n - 1, k = 0;
	while (l < r) 
	{
		int j = r;

		while (j > 0) 
		{
			if (this->Arr[j] < this->Arr[j - 1]) 
			{
				this->swapSort(this->Arr[j], this->Arr[j - 1]);
				k = j;
			}
			j--;
		}

		l = k;
		j = k;

		while (j < r) 
		{
			if (this->Arr[j] > this->Arr[j + 1]) 
			{
				this->swapSort(this->Arr[j], this->Arr[j + 1]);
				k = j;
			}
			j++;
		}

		r = k;
	}
}

ostream& operator<< (ostream& os, ShakerSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}