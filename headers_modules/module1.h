#ifndef module1_h
#define module1_h
#include <vector>
#include <string>
#include <iostream>

class Student 
{
private:
	char* name;
	std::vector<int> marks;

	int getSize(std::vector<int>& arr) {
		int s = 0;
		for (auto& i : marks) s++;
		return s;
	}

	void createName(const char* n) {
		size_t l = strlen(n);
		name = new char[l + 1];

		for (size_t i = 0; i < l + 1; i++) name[i] = n[i];
	}
public:
	Student(const char* s) { createName(s); }
	~Student() {
		delete name;
	}

	void setMark(int mark);

	int getMark(int index);

	double avgMark();

	void setName(const char* s);

	std::string getName();
};

void module1();

#endif