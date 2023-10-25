#include <iostream>
#include <string>
#include <iomanip>
#include "../headers/classwork2.h"

uint64_t Person::instanceCount = 0;

void module2() {
	/*Date today{ 20, 10, 2023 };
	Date d;
	d.setDay(3).setMonth(11).setYear(2001);*/

	/*Fraction a{ 10, 4 };
	Fraction b{ a };
	Fraction c{ Fraction { 6, 5} };*/ // Elision
	//dynamic_array<uint16_t> arr2(arr);
	Person person1(1, "Smith", "John", "Robert", { 15, 5, 1990 });
	Person person2(2, "Johnson", "Alice", "Marie", { 20, 8, 1985 });

	person1.display();
	person2.display();

	std::cout << "Total Persons: " << Person::getInstanceCount() << std::endl;
}