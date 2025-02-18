#pragma once


template <typename T>
void SelectionSort(T* start, T* end) {
	for (T* j = start; j < end - 1; ++j) {
		T* smallest = start;
		for (T* i = j + 1; i < end; ++i) {
			if (*i < *smallest) { smallest = i; }
		}
		const T temp = *smallest;
		*smallest = *j;
		*j = temp;
	}
}
