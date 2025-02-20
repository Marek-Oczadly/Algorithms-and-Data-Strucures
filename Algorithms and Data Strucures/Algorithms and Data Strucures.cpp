#include <iostream>
#include "sorting_algorithms.h"
#include <algorithm>


int main() {
	int x[] = { 3, 5, 2, 7, 2, 6, 2, 6, 8, 11 };
	const unsigned short SIZE = sizeof(x) / sizeof(int);
	SortingAlgorithms<int>::mergeSort(&x[0], &x[0] + SIZE);
	for (const int* i = &x[0]; i < &x[0] + SIZE; ++i) {
		std::cout << *i << "	  " << std::endl;
	}
	std::cout << std::endl;
}