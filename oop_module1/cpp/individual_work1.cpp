#include <string>
#include <iostream>
#include "../headers/individual_work1.h"

void module1_IW1() {
	Student s;
	s.inputStudentData();
	s.displayStudentData();

	Point p;
	if (p.loadFromFile()) {
		//Call other methods here
		p.saveToFile();
	}
	else { 
		p.inputData(); 
		//Call other methods here
		p.saveToFile();
	}
}