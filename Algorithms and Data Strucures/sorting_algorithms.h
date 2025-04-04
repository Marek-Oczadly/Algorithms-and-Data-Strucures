#pragma once
#include <algorithm>

/// @brief A series of static functions for sorting data
/// @tparam T the type of the data being sorted
template <typename T>
class SortingAlgorithms {
private:
	/// @brief Typedef for a sorting function
	typedef void(*SortFunction)(T*, T*);
	typedef bool(*OrderFunction(const T*, const T*));

	/// @brief Merges 2 sorted arrays in a merge sort
	/// @param start The start of the array being merged
	/// @param mid The midpoint between the 2 arrays being merged
	/// @param end The end point of the array being merged
	static void merge(T* start, T* mid, T* end) {
		const unsigned int n_l = mid - start + 1;
		const unsigned int n_r = end - mid;
		T* const L = new T[n_l + 1];
		T* const R = new T[n_r + 1];
		std::copy(start, mid + 1, L);
		std::copy(mid + 1, end + 1, R);
		T max_val = std::max({ L[n_l - 1], R[n_r - 1] });
		L[n_l] = max_val; R[n_r] = max_val;
		T* i = L; T* j = R;
		for (T* k = start; k <= end; ++k) {
			if (*i <= *j) { *k = *i; ++i; }
			else { *k = *j; ++j; }
		}
		// Freeing the memory
		delete[] R;
		delete[] L;
	}

	/// @brief Recursive function to implement a merge sort on an array
	/// @param start Start of the array being sorted
	/// @param end Inclusive end of the array being sorted
	static void mergeSort_(T* start, T* end) {
		if (start < end) {	// True if the start and end are greater than 1
			T* const midpoint = start + ((end - start) / 2);
			mergeSort_(start, midpoint);	// Merge sort the left half of the array
			mergeSort_(midpoint + 1, end);	// Merge sort the right half of the array
			merge(start, midpoint, end);
		}
	}

	static T* partition(T* start, T* end) {
		T* i = start;
		for (T* j = start; j < end; ++j) {
			if (*j <= *end) {
				std::swap(*i, *j);
				++i;
			}
		}
		std::swap(*i, *end);

		for (T* i = start; i <= end; ++i) {
			std::cout << *i << ' ';
		}
		std::cout << std::endl;
		return i;
	}

	static void quickSort_(T* start, T* end) {
		if (start < end) {
			T* m = partition(start, end);
			quickSort_(start, m - 1);
			quickSort_(m + 1, end);

		}
	}

public:
	/// @brief Implements the selection sort algorithm to sort an array
	/// @param start The start of the array being sorted
	/// @param end The end of the array being sorted
	static void selectionSort(T* start, T* end) {
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

	static void quickSort(T* start, T* end) {
		quickSort_(start, end - 1);
	}

	/// @brief Implements the insertion sort algorithm to sort an array
	/// @param start The start of the array being sorted
	/// @param end The end of the array being sorted
	static void insertionSort(T* start, T* end) {
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

	static void heapSort(T* start, T* end);

	/// @brief Uses the merge sort algorithm to sort an array
	/// @param start Start of the array being sorted
	/// @param end End (not inclusive) of the array being sorted
	static void mergeSort(T* start, T* end) {
		mergeSort_(start, end - 1);
	}

	static bool isSorted(const T* start, const T* end) {
		for (const T* i = start + 1; i < end; ++i) {
			if (*(i - 1) > *i) return false;
		}
		return true;
	}

	static T* binarySearch(T* start, T* end, const T& value) {
		while (start < end) {
			T* mid = start + (end - start) / 2;
			if (*mid == value) {
				return mid;
			}
			else if (*mid > value) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}
		return nullptr;
	}




	/// @brief Checks if a sorting algorithm sorts the array in ascending order
	/// @param start - The start of the array being sorted
	/// @param end - The end of the array being sorted
	/// @param func - The sorting function being tested
	/// @return - True if the array is sorted after being passed through the algorithm
	static bool isCorrect(T* start, T* end, SortFunction func) {
		func(start, end);
		return isSorted(start, end);
	}

	static void buildMaxHeap(T* start, T* end) {
		const unsigned int SIZE = end - start;
		for (T* i = start + (SIZE / 2); i >= start; --i) {
			makeHeap(start, end, i);
		}
	}
};