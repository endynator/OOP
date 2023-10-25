#pragma once

template<typename T1, typename T2>
class pair {
public:
	T1 key;
	T2 value;
	pair(T1 k, T2 v) : key(k), value(v) {}
	pair() : pair(static_cast<T1>(0), static_cast<T2>(0)) {}
	pair& operator=(const pair& other) {
		key = other.key;
		value = other.value;
		return *this;
	}
};

template<typename T1, typename T2>
class dict
{
	pair<T1, T2>* arr;
	size_t size;
public:
	bool empty = true;
	dict(size_t s) : arr{ new pair<T1, T2>[s] }, size{ s }
	{
		(s == 0) ? empty = false : empty = true;
	}
	dict() : dict(0) {}
	dict(const dict& other) : arr{ new pair<T1, T2>[other.size] }, size(other.size) {
		empty = false;
		for (size_t i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
	~dict()
	{
		if (arr != nullptr) delete[] arr;
	}

	dict& push_back(pair<T1, T2> p) {
		if (size == 0) {
			arr = new pair<T1, T2>[1];
			arr[0] = p;
			size++;
			return *this;
		}
		pair<T1, T2>* new_arr = new pair<T1, T2>[size + 1];

		for (size_t i = 0; i < size; i++) {
			new_arr[i] = arr[i];
		}
		new_arr[size] = p;
		size++;

		if (arr != nullptr) delete[] arr;
		arr = new pair<T1, T2>[size];
		for (size_t i = 0; i < size; i++) {
			arr[i] = new_arr[i];
		}
		delete[] new_arr;
		return *this;
	}
		/*for (size_t i{ 0 }; i < size + 1; i++) {
			arr[i] = new_arr[i];
		}
		size = copy_size + 1;
		delete[] new_arr;
		return *this;
	}*/

	size_t getSize() {
		return size;
	}

	pair<T1, T2>* begin() {
		return arr;
	}

	pair<T1, T2>* end() {
		return arr + size;
	}

	T2* getValues() {
		T2* temp = new T2[size];
		for (size_t i{ 0 }; i < size; i++) {
			temp[i] = arr[i].value;
		}
		return temp;
	}

	dict find(T1 key) {
		dict result;
		for (size_t i{ 0 }; i < size; i++) {
			if (arr[i].key == key) result.push_back(arr[i]);
		}
		return result;
	}
	pair<T1, T2>& operator[](const size_t& index) {
		return arr[index];
	}
	bool operator!=(const dict& other) const {
		return this->size != other.size;
	}
	bool operator==(const dict& other) const {
		return this->size == other.size;
	}
	dict& operator=(const dict& other) {
		if (this == &other) {
			// Self-assignment, no action needed
			return *this;
		}

		// Delete the current data if any
		if (arr != nullptr) {
			delete[] arr;
		}

		// Allocate new memory for the copy
		size = other.size;
		arr = new pair<T1, T2>[size];

		// Copy the elements from 'other' to 'this'
		for (size_t i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}

		return *this;
	}
};