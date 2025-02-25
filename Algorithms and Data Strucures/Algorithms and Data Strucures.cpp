#include <iostream>
#include "sorting_algorithms.h"
#include "comparison_counter.h"

typedef ComparisonCounter<int> CInt;

int main() {
	CInt x[] = { 93, 63, 67, 12, 58, 34, 76, 81, 45, 99, 21, 38, 70, 54, 85, 32, 62, 88, 49, 14, 77, 27, 95, 41, 89, 53, 26, 75, 59, 19, 73, 66, 92, 31, 83, 24, 68, 46, 97, 39, 22, 52, 90, 18, 44, 80, 56, 30, 71, 64, 33, 57, 16, 86, 29, 48, 60, 13, 84, 72, 25, 79, 50, 87 };
	const unsigned short SIZE = sizeof(x) / sizeof(CInt);
	ComparisonCounter<int>::resetCount();
	SortingAlgorithms<CInt>::mergeSort(&x[0], &x[0] + SIZE);
	
	for (const CInt* i = &x[0]; i < &x[0] + SIZE; ++i) {
		std::cout << *i << "  ";
	}
	std::cout << std::endl;
	std::cout << CInt::getCount() << std::endl;
	return 0;
}