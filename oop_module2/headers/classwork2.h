#pragma once
#include <iostream>
#include <cstring>

using namespace std;

class Point
{
public:
	int x;
	int y;
	Point() : x{ 0 }, y{ 0 } {
		cout << "Point default cons." << endl;
	}
	Point(int newX, int newY) : x{ newX }, y{ newY }
	{
		cout << "Point with params cons." << endl;
	}
};

class Rectangle
{
private:
	Point left_upper_corner;
	int width;
	int height;
public:
	Rectangle() : left_upper_corner{ 10, 10 }, width(10), height(10) {
		cout << "Rectangle default cons." << endl;
	}
	Rectangle(int w, int h) : left_upper_corner{ 10, 10 }, width(w), height(h) {
		cout << "Rectangle with params cons." << endl;
	}
};

struct bday {
	uint8_t day;
	uint8_t month;
	uint16_t year;
};

class Person
{
	char* firstName;
	char* lastName;
	char* middleName;
	bday dateOfBirth;
	uint64_t id;

	static uint64_t instanceCount;
public:
    Person(uint64_t id, const char* last, const char* first, const char* middle, bday date)
        : id(id), dateOfBirth(date) {
        lastName = new char[strlen(last) + 1];
        strcpy_s(lastName, strlen(last) + 1, last);

        firstName = new char[strlen(first) + 1];
        strcpy_s(firstName, strlen(first) + 1, first);

        middleName = new char[strlen(middle) + 1];
        strcpy_s(middleName, strlen(middle) + 1, middle);

        instanceCount++;
    }

    Person()
        : Person(0, "", "", "", { 0, 0, 0 }) {
    }

    Person(const Person& other)
        : id(other.id), dateOfBirth(other.dateOfBirth) {
        lastName = new char[strlen(other.lastName) + 1];
        strcpy_s(lastName, strlen(other.lastName) + 1, other.lastName);

        firstName = new char[strlen(other.firstName) + 1];
        strcpy_s(firstName, strlen(other.firstName) + 1, other.firstName);

        middleName = new char[strlen(other.middleName) + 1];
        strcpy_s(middleName, strlen(other.middleName) + 1, other.middleName);

        instanceCount++;
    }

    ~Person() {
        delete[] lastName;
        delete[] firstName;
        delete[] middleName;
        instanceCount--;
    }

    uint64_t getId() const {
        return id;
    }

    void setId(uint64_t newId) {
        id = newId;
    }

    const char* getLastName() const {
        return lastName;
    }

    void setLastName(const char* newLastName) {
        delete[] lastName;
        lastName = new char[strlen(newLastName) + 1];
        strcpy_s(lastName, strlen(newLastName) + 1, newLastName);
    }

    const char* getFirstName() const {
        return firstName;
    }

    void setFirstName(const char* newFirstName) {
        delete[] firstName;
        firstName = new char[strlen(newFirstName) + 1];
        strcpy_s(firstName, strlen(newFirstName) + 1, newFirstName);
    }

    const char* getMiddleName() const {
        return middleName;
    }

    void setMiddleName(const char* newMiddleName) {
        delete[] middleName;
        middleName = new char[strlen(newMiddleName) + 1];
        strcpy_s(middleName, strlen(newMiddleName) + 1, newMiddleName);
    }

    bday getBirthDate() const {
        return dateOfBirth;
    }

    void setBirthDate(bday newBirthDate) {
        dateOfBirth = newBirthDate;
    }

    void display() const {
        std::cout << "ID: " << id << std::endl;
        std::cout << "Last Name: " << lastName << std::endl;
        std::cout << "First Name: " << firstName << std::endl;
        std::cout << "Middle Name: " << middleName << std::endl;
        std::cout << "Birth Date: " << dateOfBirth.day << "/" << dateOfBirth.month << "/" << dateOfBirth.year << std::endl;
    }

    static uint64_t getInstanceCount() {
        return instanceCount;
    }
};

class NumberStorage
{

};

class Date
{
private:

	uint8_t day;
	uint8_t month;
	uint16_t year;
public:
	Date(uint8_t d, uint8_t m, uint16_t y)
		: day{ d }, month{ m }, year{ y } {}
	Date() : Date(1, 1, 1970) {}

	void print() {
		std::cout << this->day << "." << this->month << "." << this->year << std::endl;
	}

	Date& setDay(uint8_t _day) { day = _day; return *this; }
	Date& setMonth(uint8_t _month) { month = _month; return *this; }
	Date& setYear(uint16_t _year) { year = _year; return *this; }
};

class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction(int num, int den) : numerator(num), denominator(den)
	{
		cout << "Created object at " << this << endl;
	}
	Fraction() : Fraction(1, 1) {}

	Fraction(const Fraction& obj) : numerator{ obj.numerator }, denominator{ obj.denominator }
	{
		cout << "Created object at " << this << endl;
	}

	~Fraction() {
		cout << "Deleted object at " << this << endl;
	}

	void print() {
		cout << numerator << "/" << denominator << endl;
	}
};

void module2();