#pragma once
#include <vector>


enum class Colours: unsigned char {
	black, white, grey
};

struct Node {
	std::vector<Node*> connections;
	Colours colour;
};

