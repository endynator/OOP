#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "dict.h"

constexpr unsigned short int MIN_GRADE = 1;
constexpr unsigned short int MAX_GRADE = 12;
extern std::string studentsFile;
extern std::string subjectsFile;
extern std::string gradesFile;

class Subject {
public:
	Subject(const std::string& name) : name(name) {}
	std::string getName() const { return name; }
private:
	std::string name;
};

class Student
{
public:
    Student(const std::string& name) : name(name) {}

    void addGrade(const Subject& subject, unsigned short int grade) {
        grades.push_back({ &subject, grade });
    }

    std::string getName() const { return name; }

    unsigned short int* getGrades(const Subject& subject) {
        auto it = grades.find(&subject);
        return it.getValues();
    }
    size_t getSize() {
        return grades.getSize();
    }
private:
    std::string name;
    dict<const Subject*, unsigned short int> grades;
};

class Group {
public:
    Group(const std::string& name) : name(name) {}

    void addStudent(const Student& student) {
        students.push_back(student);
    }

    void addSubject(const Subject& subject) {
        subjects.push_back(subject);
    }
    Student& getStudent(const std::string& name) {
        for (auto& student : students) {
            if (student.getName() == name) {
                return student;
            }
        }
        throw std::exception("Couldn't find student.");
    }
    Subject& getSubject(const std::string& name) {
        for (auto& subject : subjects) {
            if (subject.getName() == name) {
                return subject;
            }
        }
        throw std::exception("Couldn't find subject.");
    }

    void displayStudentGrades();
    void displayAverageGrades();
    void displayAverageGradesBySubject();
    void displayGroupAverage();
    void displayMaxMinGradesBySubject();
    void writeDataToFiles();
    void readDataFromFiles();
private:
    std::string name;
    std::vector<Student> students;
    std::vector<Subject> subjects;
};

// Function to load students from a file
std::vector<Student> loadStudentsFromFile(const std::vector<Subject>& subjects);

// Function to load subjects from a file
std::vector<Subject> loadSubjectsFromFile();

// Read filenames to the configuration file
void readFilenamesFromConfig();

// Write filenames to the configuration file
void writeFilenamesToConfig();

void homework1();