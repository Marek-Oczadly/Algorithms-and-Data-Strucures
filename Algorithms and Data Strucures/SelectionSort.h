#pragma once


template <typename T>
void SelectionSort(T* start, T* end) {
	for (T* j = start; j < end; ++j) {
		T* smallest = j;
		for (T* i = j; i < end; ++i) {
			if (*i < *smallest) { smallest = i; }
		}
		const T temp = *smallest;
		*smallest = *j;
		*j = temp;
	}
}
