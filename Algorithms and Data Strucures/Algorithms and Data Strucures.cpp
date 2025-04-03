#include <iostream>
#include "sorting_algorithms.h"
#include "comparison_counter.h"

typedef ComparisonCounter<int> CInt;
typedef SortingAlgorithms<CInt> Algos;


int main() {
	CInt x[] = { 57, 82, 19, 73, 99, 2, 61, 34, 91, 11, 42, 23, 68, 4, 87, 25, 76, 15, 37, 89, 13, 50, 63, 6, 84, 31, 97, 8, 55, 78, 21, 66, 3, 44, 17, 92, 29, 60, 47, 93, 12, 53, 80, 36, 5, 70, 27, 88, 32, 64, 1, 41, 62, 22, 75, 14, 59, 38, 81, 9, 30, 67, 48, 95, 7, 43, 72, 26, 83, 20, 58, 40, 10, 90, 35, 16, 52, 74, 28, 85, 24, 69, 39, 18, 56, 77, 49, 98, 33, 65, 71, 46, 79, 54, 86, 45, 94, 100, 51 };
	const unsigned short SIZE = sizeof(x) / sizeof(CInt);
	CInt::resetCount();
	
	Algos::insertionSort(&x[0], &x[0] + SIZE);

	CInt* ptr = Algos::binarySearch(&x[0], &x[0] + SIZE, CInt(12));

	std::cout << *ptr << std::endl;
	
	if (Algos::isSorted(&x[0], &x[0] + SIZE)) { std::cout << "True \n";	}
	else { std::cout << "False \n"; }
	
	return 0;
}