#pragma once


template <typename T>
void selectionSort(T* start, T* end) {
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

template <typename T>
void insertionSort(T* start, T* end) {
	for (T* j = start + 1; j < end; ++j) {
		const T key = *j;
		T* i = j - 1;
		while (i >= start && *i > key) {
			*(i + 1) = *i;
			--i;
		}
		*(i + 1) = key;
	}
}
