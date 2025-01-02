#include "ShellSort.h"

void ShellSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void ShellSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void ShellSort::Sort()
{
	int i, j, x, len, step;
	step = 0;
	int k = 3;
	int h[3] = { 5,3,1 };
	while (step < k)
	{
		len = h[step];
		i = len;
		while (i < this->n) {
			x = this->Arr[i];
			j = i - len;
			while ((x < this->Arr[j]) && (j >= 0))
			{
				this->Arr[j + len] = this->Arr[j];
				j = j - len;
			}
			this->Arr[j + len] = x;
			i++;
		}
		step++;
	}
}

ostream& operator<< (ostream& os, ShellSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}