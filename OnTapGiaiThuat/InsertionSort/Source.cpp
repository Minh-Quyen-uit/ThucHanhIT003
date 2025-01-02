#include <iostream>
#include "InterchangeSort.h"
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "ShakerSort.h"
#include "InsertionSort.h"
#include "BinaryInsertionSort.h"
#include "ShellSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "MergeSort.h"

using namespace std;


int main() {
	int n = 7;
	int a[7] = {5,1,6,8,9,1,3};
	
	MergeSort x;
	x.addArray(a, n);
	x.Sort();
	cout << x;

	return 1;
}