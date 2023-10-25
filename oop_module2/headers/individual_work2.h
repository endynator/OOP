#pragma once
#include <iostream>

using namespace std;

template<typename T>
class dynamic_array
{
private:
	void merge(size_t l, size_t m, size_t r) {
		size_t n1 = m - l + 1;
		size_t n2 = r - m;

		// Create temporary arrays to hold the subarrays
		T* L = new T[n1];
		T* R = new T[n2];

		// Copy data to temporary arrays L[] and R[]
		for (size_t i = 0; i < n1; i++) {
			L[i] = arr[l + i];
		}
		for (size_t j = 0; j < n2; j++) {
			R[j] = arr[m + 1 + j];
		}

		// Merge the temporary arrays back into arr[l..r]
		size_t i = 0, j = 0, k = l;
		while (i < n1 && j < n2) {
			if (L[i] <= R[j]) {
				arr[k] = L[i];
				i++;
			}
			else {
				arr[k] = R[j];
				j++;
			}
			k++;
		}

		// Copy the remaining elements of L[], if any
		while (i < n1) {
			arr[k] = L[i];
			i++;
			k++;
		}

		// Copy the remaining elements of R[], if any
		while (j < n2) {
			arr[k] = R[j];
			j++;
			k++;
		}

		// Clean up temporary arrays
		delete[] L;
		delete[] R;
	}

	// Recursive merge sort algorithm
	void mergeSort(size_t l, size_t r) {
		if (l < r) {
			// Find the middle point
			size_t m = l + (r - l) / 2;

			// Recursively sort the first and second halves
			mergeSort(l, m);
			mergeSort(m + 1, r);

			// Merge the sorted halves
			merge(l, m, r);
		}
	}
public:
	dynamic_array(size_t s) : arr{ new T[s] {} }, size{ s }
	{
		cout << "Created array on " << this << endl;
		cout << "Size: " << size << endl;
	}
	dynamic_array() : dynamic_array(0) {}
	dynamic_array(const dynamic_array& other) : arr(new T[other.size]), size(other.size) {
		for (size_t i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	~dynamic_array()
	{
		cout << "Destroying array on " << this << endl;
		if (arr != nullptr && arr) delete[] arr;
	}

	template<typename... Args>
	void newData(Args... values) {
		if (sizeof...(values) > 0) {
			if (arr != nullptr) {
				delete[] arr;
			}
			size = sizeof...(values);
			arr = new T[size]{ static_cast<T>(values)... };
		}
	}

	void resize(size_t s) {
		if (s == size) return;
		T* new_arr = new T[s];
		const size_t min_size = std::min(size, s);

		for (size_t i = 0; i < min_size; i++) {
			if (i == 1 && s == 0) break;
			new_arr[i] = { arr[i] };
		}
		delete[] arr;
		arr = new_arr;
		size = s;
	}

	void randomize() {
		for (size_t i{ 0 }; i < size; i++) {
			arr[i] = rand() % 10;
		}
	}

	void display() {
		for (size_t i{ 0 }; i < size; i++) {
			cout << arr[i] << "; ";
		}
		cout << endl;
	}

	void sort() {
		if (size > 1) {
			mergeSort(0, size - 1);
		}
	}

	T min() {
		if (size == 0) {
			throw std::out_of_range("Array is empty");
		}

		T min_value = arr[0];
		for (size_t i = 1; i < size; i++) {
			if (arr[i] < min_value) {
				min_value = arr[i];
			}
		}
		return min_value;
	}

	T max() {
		if (size == 0) {
			throw std::out_of_range("Array is empty");
		}

		T max_value = arr[0];
		for (size_t i = 1; i < size; i++) {
			if (arr[i] > max_value) {
				max_value = arr[i];
			}
		}
		return max_value;
	}

	T& operator[](const size_t& index) {
		return arr[index];
	}
private:
	T* arr;
	size_t size;
};


void work2();