#include "../headers/homework1.h"
#include <vector>
#include <sstream>
#include <string>

std::string studentsFile = "students.txt";
std::string subjectsFile = "subjects.txt";
std::string gradesFile = "grades.txt";

void readFilenamesFromConfig() {
	std::ifstream configFile("config.txt");
	if (configFile) {
		configFile.seekg(0, std::ios::end);
		if (configFile.tellg() == 0) {
			std::cout << "Configuration file is empty. Using default filenames.\n";
			return;
		}

		configFile >> studentsFile >> subjectsFile >> gradesFile;
		std::cout << "Filenames loaded from the configuration file.\n";
	}
	else {
		std::cout << "Configuration file not found. Using default filenames.\n";
	}
}

void writeFilenamesToConfig() {
	std::ofstream configFile("config.txt");
	configFile << studentsFile << " " << subjectsFile << " " << gradesFile;
	std::cout << "Filenames saved to the configuration file.\n";
}

void homework1() {
	readFilenamesFromConfig();
	Group group("MyGroup");

	group.readDataFromFiles();
	// Display information
	unsigned short int choice;
	while (true) {
		std::cout << "\nMenu:\n";
		std::cout << "1. Display Student Grades\n";
		std::cout << "2. Display Average Grades\n";
		std::cout << "3. Display Average Grades by Subject\n";
		std::cout << "4. Display Group Average\n";
		std::cout << "5. Display Group Rating\n";
		std::cout << "0. Exit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			group.displayStudentGrades();
			break;
		case 2:
			group.displayAverageGrades();
			break;
		case 3:
			group.displayAverageGradesBySubject();
			break;
		case 4:
			group.displayGroupAverage();
			break;
		case 5:
			group.displayMaxMinGradesBySubject();
			break;
		case 0:
			return;
		default:
			std::cout << "Invalid choice. Please try again.\n";
		}
	}
}