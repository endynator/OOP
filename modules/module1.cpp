#include <iostream>
#include <string>
#include <iomanip>
#include "../headers_modules/module1.h"

using namespace std;

void module1() {
	cout << "Students progress\n\n";

	const size_t size = 2;

	Student* students = new Student[size]
	{
		{"John"},
		{"Peter the 3rd"}
	};

	students[0].setMark(11);
	students[0].setMark(9);
	students[0].setMark(6);

	students[1].setMark(1);
	students[1].setMark(8);
	students[1].setMark(6);

	double s = 0;

	for (auto student = students; student < students + size; student++) {
		double avg = student->avgMark();

		cout << "Avarage: " << fixed << setprecision(2) << avg << endl;
		s += avg;
	};

	cout << "Avarage (All): " << fixed << setprecision(2) << s / size << endl;

	// See the declaration of "Student" at "../headers_modules/module1.h"
	Student student("Jimmy Bil Bob");

	student.setMark(9);
	student.setMark(7);
	student.setMark(3);

	//cout << fixed << setprecision(2) << student.avgMark();
	/*strcpy_s(student.name, 20, "John");
	student.marks[0] = 9;

	cout << student.name << endl << student.marks[0] << endl;*/
}