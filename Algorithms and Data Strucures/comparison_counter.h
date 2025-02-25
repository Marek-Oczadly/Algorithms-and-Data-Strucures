#pragma once

template <typename T>
class ComparisonCounter {
	T value;
	static void increment() {
		ComparisonCounter::count++;
	}
public:
	static unsigned int count;
	static unsigned int getCount() noexcept {
		return count;
	}

	ComparisonCounter(const T& value) : value(value) {}
	ComparisonCounter(const ComparisonCounter<T>& other) {
		value = other.value;
	}

	bool operator >(const ComparisonCounter<T>& other) {
		ComparisonCounter<T>::increment();
		return value > other.value;
	}
	bool operator <(const ComparisonCounter<T>& other) {
		ComparisonCounter<T>::increment();
		return value > other.value;
	}
	bool operator ==(const ComparisonCounter<T>& other) {
		ComparisonCounter<T>::increment();
		return value == other.value;
	}
	bool operator >=(const ComparisonCounter<T>& other) {
		ComparisonCounter<T>::increment();
		return value >= other.value;
	}
	bool operator <=(const ComparisonCounter<T>& other) {
		ComparisonCounter<T>::increment();
		return value <= other.value;
	}
	operator T& () {
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