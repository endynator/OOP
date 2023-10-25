#include "../headers/homework1.h"
#include <sstream>
#include <fstream>

void Group::writeDataToFiles() {
    // Write students to students.txt
    std::ofstream studentsOutput(studentsFile);
    for (const auto& student : students) {
        studentsOutput << student.getName() << "\n";
    }
    studentsOutput.close();

    // Write subjects to subjects.txt
    std::ofstream subjectsOutput(subjectsFile);
    for (const auto& subject : subjects) {
        subjectsOutput << subject.getName() << "\n";
    }
    subjectsOutput.close();

    // Write grades to grades.txt
    std::ofstream gradesOutput(gradesFile);
    for (auto& student : students) {
        std::string studentName = student.getName();
        for (const auto& subject : subjects) {
            auto grades = student.getGrades(subject);
            for (size_t i = 0; i < student.getSize(); ++i) {
                gradesOutput << studentName << " " << subject.getName() << " " << grades[i] << "\n";
            }
        }
    }
    gradesOutput.close();
}

void Group::readDataFromFiles() {
    // Read students from students.txt
    std::ifstream studentsInput(studentsFile);
    std::string studentName;
    while (std::getline(studentsInput, studentName)) {
        students.push_back(Student(studentName));
    }
    studentsInput.close();

    // Read subjects from subjects.txt
    std::ifstream subjectsInput(subjectsFile);
    std::string subjectName;
    while (std::getline(subjectsInput, subjectName)) {
        subjects.push_back(Subject(subjectName));
    }
    subjectsInput.close();

    // Read grades from grades.txt
    std::ifstream gradesInput(gradesFile);
    std::string line;
    while (std::getline(gradesInput, line)) {
        bool breakAll = false;
        std::istringstream iss(line);
        std::string studentName, subjectName;
        unsigned short int grade;
        if (iss >> studentName >> subjectName >> grade) {
            for (auto& student : students) {
                if (student.getName() == studentName) {
					for (auto& subject : subjects) {
                        if (subject.getName() == subjectName) {
                            student.addGrade(subject, grade);
							breakAll = true;
							break;
                        }
                        if (breakAll) break;
                    }
                    if (breakAll) break;
                }
            }
            if (breakAll) continue;
        }
    }
    gradesInput.close();
}

void Group::displayStudentGrades() {
    for (auto& student : students) {
        std::cout << std::endl << "Student: " << student.getName() << std::endl;
        for (const auto& subject : subjects) {
            std::cout << "Subject: " << subject.getName() << " - Grades: ";
            auto grades = student.getGrades(subject);
            for (size_t i = 0; i < student.getSize(); ++i) {
                if (grades[i] >= MIN_GRADE && grades[i] <= MAX_GRADE) {
                    std::cout << grades[i];
                    if (i < student.getSize()) {
                        std::cout << ", ";
                    }
                }
            }
            std::cout << std::endl;
        }
    }
}

void Group::displayAverageGrades() {
    std::cout << "Average Grades:\n";
    for (auto& student : students) {
        double totalGrade = 0;
        size_t totalValidGrades = 0;

        for (const auto& subject : subjects) {
            auto grades = student.getGrades(subject);
            for (size_t i = 0; i < student.getSize(); ++i) {
                if (grades[i] >= MIN_GRADE && grades[i] <= MAX_GRADE) {
                    totalGrade += grades[i];
                    totalValidGrades++;
                }
            }
        }

        if (totalValidGrades > 0) {
            double averageGrade = totalGrade / totalValidGrades;
            std::cout << "Student: " << student.getName() << " - Average Grade: " << averageGrade << std::endl;
        }
    }
}

void Group::displayAverageGradesBySubject() {
    std::cout << "Average Grades by Subject:\n";
    for (const auto& subject : subjects) {
        double totalGrade = 0;
        size_t totalValidGrades = 0;

        for (auto& student : students) {
            auto grades = student.getGrades(subject);
            for (size_t i = 0; i < student.getSize(); ++i) {
                if (grades[i] >= MIN_GRADE && grades[i] <= MAX_GRADE) {
                    totalGrade += grades[i];
                    totalValidGrades++;
                }
            }
        }

        if (totalValidGrades > 0) {
            double averageGrade = totalGrade / totalValidGrades;
            std::cout << "Subject: " << subject.getName() << " - Average Grade: " << averageGrade << std::endl;
        }
    }
}

void Group::displayGroupAverage() {
    double totalGrade = 0;
    size_t totalValidGrades = 0;

    for (auto& student : students) {
        for (const auto& subject : subjects) {
            auto grades = student.getGrades(subject);
            for (size_t i = 0; i < student.getSize(); ++i) {
                if (grades[i] >= MIN_GRADE && grades[i] <= MAX_GRADE) {
                    totalGrade += grades[i];
                    totalValidGrades++;
                }
            }
        }
    }

    if (totalValidGrades > 0) {
        double groupAverage = totalGrade / totalValidGrades;
        std::cout << "Group Average Grade: " << groupAverage << std::endl;
    }
    else {
        std::cout << "Group has no valid grades. Cannot calculate group average." << std::endl;
    }
}

void Group::displayMaxMinGradesBySubject() {
    std::cout << "Max and Min Grades by Subject:\n";
    for (const auto& subject : subjects) {
        unsigned short int maxGrade = MIN_GRADE;
        unsigned short int minGrade = MAX_GRADE;
        std::string maxStudent = ""; 
        std::string minStudent = ""; 

        for (auto& student : students) {
            unsigned short int* grades = student.getGrades(subject);
            for (size_t i = 0; i < student.getSize(); ++i) {
                unsigned short int grade = grades[i];
                if (grades[i] < MIN_GRADE && grades[i] > MAX_GRADE) continue;
                if (grade > maxGrade) {
                    maxGrade = grade;
                    maxStudent = student.getName();
                }
                if (grade < minGrade) {
                    minGrade = grade;
                    minStudent = student.getName();
                }
            }
        }

        std::cout << "Subject: " << subject.getName() << "\n";
        if (!maxStudent.empty()) {
            std::cout << "Max Grade: " << maxGrade << " (Student: " << maxStudent << ")\n";
        }
        else {
            std::cout << "No maximum grade found for this subject.\n";
        }
        if (!minStudent.empty()) {
            std::cout << "Min Grade: " << minGrade << " (Student: " << minStudent << ")\n";
        }
        else {
            std::cout << "No minimum grade found for this subject.\n";
        }
    }
}
