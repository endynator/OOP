#include "headers/classwork1.h"

double Student::avgMark() {
	double avg = 0;
	for (auto& i : marks) if (i != 0) avg += i;
	return avg / getSize(marks);
}

void Student::setMark(int mark) {
	marks.push_back(mark);
}

inline int Student::getMark(int index) {
	return marks[index];
}

inline void Student::setName(const char* s) {
	delete[] name;
	createName(s);
}

inline char* Student::getName() {
	return name;
}