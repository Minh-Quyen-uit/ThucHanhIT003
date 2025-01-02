#include "MergeSort.h"

const int MAX = 1000;
int b[MAX], c[MAX];
int nb, nc;

void MergeSort::addArray(int a[], int n)
{
	this->n = n;
	this->Arr = a;
}

void MergeSort::swapSort(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

int MergeSort::Min(int a, int b)
{
	return (a > b) ? b : a;
}

void MergeSort::Distribute(int n, int& Nb, int& Nc, int k) 
{
	int i, pa, pb, pc;
	pa = pb = pc = 0;
	while (pa < n)
	{
		for (i = 0; (pa < n) && (i < k); i++, pa++, pb++)
			b[pb] = this->Arr[pa];
		for (i = 0; (pa < n) && (i < k); i++, pa++, pc++)
			c[pc] = this->Arr[pa];
	}
	Nb = pb;
	Nc = pc;
}

void MergeSort::Merge(int Nb, int Nc, int k) 
{
	int p, pb, pc, ib, ic, kb, kc;
	p = pb = pc = ib = ic = 0;
	while ((Nb > 0) && (Nc > 0))
	{
		kb = Min(k, Nb);
		kc = Min(k, Nc);
		if (b[pb + ib] <= c[pc + ic])
		{
			this->Arr[p++] = b[pb + ib];
			ib++;
			if (ib == kb)
			{
				for (ic; ic < kc; ic++)
					this->Arr[p++] = c[pc + ic];
				pb += kb;
				pc += kc;
				ib = ic = 0;
				Nb -= kb;
				Nc -= kc;
			}
		}
		else
		{
			this->Arr[p++] = c[pc + ic];
			ic++;
			if (ic == kc)
			{
				for (ib; ib < kb; ib++)
					this->Arr[p++] = b[pb + ib];
				pb += kb;
				pc += kc;
				ib = ic = 0;
				Nb -= kb;
				Nc -= kc;
			}
		}
	}
}

void MergeSort::Sort()
{
	int k;
	for (k = 1; k < this->n; k *= 2)
	{
		this->Distribute(this->n, nb, nc, k);
		this->Merge(nb, nc, k);
	}
}

ostream& operator<< (ostream& os, MergeSort x)
{
	for (int i = 0; i < x.n; i++) {
		os << x.Arr[i] << " ";
	}
	os << "\n";
	return os;
}