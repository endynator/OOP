#ifndef module2_h
#define module2_h

#include <iostream>
#include <string>

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

class Person 
{
	char* name;
	uint16_t age;
	uint32_t socialId;
public:

	Person(const char* newName, uint16_t newAge, uint32_t newSocialId)
		: name{ newName ? new char[strlen(newName) + 1] : nullptr }, age{ newAge }, socialId{ newSocialId }
	{
		if (name) {
			strcpy_s(name, strlen(newName) + 1, newName);
		}
	}

	Person() : Person{ nullptr, 0, 0 } {}

	Person(const char* newName) : Person{ newName, 0, 0 } {}
	Person(const char* newName, uint16_t newAge) : Person{ newName, newAge, 0 } {}
};

void module2();
#endif