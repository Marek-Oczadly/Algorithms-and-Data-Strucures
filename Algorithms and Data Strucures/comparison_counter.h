#pragma once
#include <iostream>

/// @brief Wrapper class for any arithmetic class that counts how many comparisons are done to evaluate the effiency of a sorting algorithm
/// @tparam T Any arithmetic type that is to be sorted. Tested with int, double, float.
template <typename T>
class ComparisonCounter {
	T value;
	static void increment() {
		ComparisonCounter<T>::count++;
	}
public:
	static unsigned int count;
	static unsigned int getCount() noexcept {
		return ComparisonCounter<T>::count;
	}
	static void resetCount() noexcept {
		ComparisonCounter<T>::count = 0;
	}
	ComparisonCounter() : value(T()) {}

	ComparisonCounter(const T& value) : value(value) {}
	ComparisonCounter(const ComparisonCounter<T>& other) {
		value = other.value;
	}

	bool operator >(const ComparisonCounter<T>& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value > other.value;
	}
	bool operator <(const ComparisonCounter<T>& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value < other.value;
	}
	bool operator ==(const ComparisonCounter<T>& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value == other.value;
	}
	bool operator >=(const ComparisonCounter<T>& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value >= other.value;
	}
	bool operator <=(const ComparisonCounter<T>& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value <= other.value;
	}
	bool operator >(const T& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value > other;
	}
	bool operator <(const T& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value < other;
	}
	bool operator ==(const T& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value == other;
	}
	bool operator >=(const T& other) const noexcept{
		ComparisonCounter<T>::increment();
		return value >= other;
	}
	bool operator <=(const T& other) const noexcept {
		ComparisonCounter<T>::increment();
		return value <= other;
	}
	operator T& () noexcept {
		return value;
	}

	operator const T& () const noexcept {
		return value;
	}
	ComparisonCounter<T>& operator =(const ComparisonCounter<T>& other) {
		value = other.value;
		return *this;
	}

	ComparisonCounter<T>& operator =(const T& other) {
		value = other;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const ComparisonCounter<T>& obj) {
		os << obj.value;
		return os;

	}
};

template <typename T>
unsigned int ComparisonCounter<T>::count = 0;