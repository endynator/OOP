#ifndef module1_h
#define module1_h
#include <vector>
#include <string>
#include <iostream>

class Student {
private:
	const char* name = new char;
	std::vector<int> marks;

	int getSize(std::vector<int> &arr) {
		int s = 0;
		for (auto& i : marks) s++;
		return s;
	}
public:
	Student(const char* s)
		: name(s){}

	void setMark(int mark);

	int getMark(int index);

	double avgMark();

	void setName(const char* s);

	std::string getName();
};

void module1();

#endif