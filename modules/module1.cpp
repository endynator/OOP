#include <iostream>
#include <string>
#include <iomanip>
#include "../headers_modules/module1.h"

using namespace std;

void module1() {
	cout << "Students progress\n\n";

	// See the declaration of "Student" at "../headers_modules/module1.h"
	Student student("Jimmy Bil Bob");

	student.setMark(9);
	student.setMark(7);
	student.setMark(3);

	cout << fixed << setprecision(2) << student.avgMark();
	/*strcpy_s(student.name, 20, "John");
	student.marks[0] = 9;

	cout << student.name << endl << student.marks[0] << endl;*/
}