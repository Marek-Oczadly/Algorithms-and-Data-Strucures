#pragma once


template <typename T>
class BinarySearchTree;


template <typename T>
class Node {
	friend class BinarySearchTree<T>;
	Node *predecessor, *l, *r;
	const T value;
public:
	Node(const T& value) : value(value) {}
	~Node() {
		delete l;
		delete r;
	}
};

template <typename T>
class BinarySearchTree {
private:
	Node<T>* root;
public:
	BinarySearchTree(const T* start, const T* end) {
		T** ls = new T * [end - start];
		
	}

	~BinarySearchTree() {
		delete root;
	}
};