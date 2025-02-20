#include <iostream>
#include "sorting_algorithms.h"


int main() {
	int x[] = { 83, 45, 22, 91, 7, 12, 67, 24, 95, 43, 56, 89, 14, 3, 78, 64, 51, 18, 39, 11, 97, 26, 60, 85, 9, 30, 63, 99, 27, 34, 48, 88, 6, 75, 21, 79, 58, 29, 13, 54, 92, 2, 73, 40, 68, 19, 35, 53, 98, 47, 31, 81, 5, 62, 90, 33, 70, 25, 76, 8, 41, 84, 57, 17, 49, 77, 66, 1, 50, 86, 28, 94, 15, 55, 38, 87, 46, 4, 71, 61, 32, 72, 10, 69, 82, 23, 93, 16, 52, 42, 74, 37, 59, 44, 36, 20, 96, 80, 65, 84 };
	const unsigned short SIZE = sizeof(x) / sizeof(int);
	std::cout <<SortingAlgorithms<int>::isCorrect(&x[0], &x[0] + SIZE, SortingAlgorithms<int>::mergeSort) << std::endl;
}