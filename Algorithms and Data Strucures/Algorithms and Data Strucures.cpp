#include <iostream>
#include "sorting_algorithms.h"
#include "comparison_counter.h"
#include "Dynamic_Programming.h"

int main() {
	GreedyAlgorithm x = { {"event a", 1, 1.5}, {"event b", 2, 2.5}, {"event c", 3, 3.5} , {"event d", 2.75, 3} };
	std::cout << x << std::endl;
	
	return 0;
}