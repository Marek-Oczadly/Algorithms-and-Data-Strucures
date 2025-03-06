#pragma once
#include <algorithm>

template <typename T>
class Heap {
private:
	static T* left(T* start, T* i) noexcept {
		++i;
		return start + 2 * (i - start) - 1;
	}

	static const T* left(const T* start, const T* i) noexcept {
		++i;
		return start + 2 * (i - start) - 1;
	}

	static T* right(T* start, T* i) noexcept {
		++i;
		return start + 2 * (i - start);
	}

	static const T* right(const T* start, const T* i) noexcept {
		++i;
		return start + 2 * (i - start);
	}

	static void makeHeap(T* start, T* end, T* i) {
		T* l = left(start, i);
		T* r = right(start, i);
		T* big = i;
		if (l < end and *l > *big) big = l;
		if (r < end and *r > *big) big = r;
		if (big != i) {
			std::swap(*i, *big);
			makeHeap(start, end, big);
		}
	}
public:

	static void buildMaxHeap(T* start, T* end) {
		const unsigned int SIZE = end - start;
		for (T* i = start + (SIZE / 2); i >= start; --i) {
			makeHeap(start, end, i);
		}
	}

	static bool isHeapSorted(const T* start, const T* end) {
		const unsigned int size = end - start;
		for (const T* i = start; i <= start + size / 2; ++i) {
			const T* l, * r;
			l = left(start, i);
			r = right(start, i);
			if (*l > *i or *r > *i) {
				return false;
			}
		}
		return true;
	}

	static T extractMax(T* start, T* end) {
		const unsigned int SIZE = end - start;
		if (SIZE < 1) throw std::exception();
		T max = *start;
		*start = SIZE;
		makeHeap()
	}
};
