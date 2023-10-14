#ifndef module1_IW_h
#define module1_IW_h
#include <string>
#include <iostream>
#include <fstream>

class Student {
private:
	std::string fullName;
	std::string birthDate;
	std::string phoneNumber;
	std::string city;
	std::string country;
	std::string schoolName;
	std::string schoolCity;
	std::string schoolCountry;
	unsigned int groupNumber;
public:
	Student() : fullName(""), birthDate(""), phoneNumber(""), city(""), country(""),
		schoolName(""), schoolCity(""), schoolCountry(""), groupNumber(0) {}

    void inputStudentData() {
        std::cout << "Enter full name: ";
        std::getline(std::cin, fullName);
        std::cout << "Enter birth date: ";
        std::getline(std::cin, birthDate);
        std::cout << "Enter phone number: ";
        std::getline(std::cin, phoneNumber);
        std::cout << "Enter city: ";
        std::getline(std::cin, city);
        std::cout << "Enter country: ";
        std::getline(std::cin, country);
        std::cout << "Enter school name: ";
        std::getline(std::cin, schoolName);
        std::cout << "Enter school city: ";
        std::getline(std::cin, schoolCity);
        std::cout << "Enter school country: ";
        std::getline(std::cin, schoolCountry);
        std::cout << "Enter group number: ";
        std::cin >> groupNumber;
    }

    void displayStudentData() {
        std::cout << "Full Name: " << fullName << std::endl;
        std::cout << "Birth Date: " << birthDate << std::endl;
        std::cout << "Phone Number: " << phoneNumber << std::endl;
        std::cout << "City: " << city << std::endl;
        std::cout << "Country: " << country << std::endl;
        std::cout << "School Name: " << schoolName << std::endl;
        std::cout << "School City: " << schoolCity << std::endl;
        std::cout << "School Country: " << schoolCountry << std::endl;
        std::cout << "Group Number: " << groupNumber << std::endl;
    }

    // Accessors (getters and setters)
    std::string getFullName() { return fullName; }
    void setFullName(const std::string& name) { fullName = name; }

    std::string getBirthDate() { return birthDate; }
    void setBirthDate(const std::string& date) { birthDate = date; }

    std::string getPhoneNumber() { return phoneNumber; }
    void setPhoneNumber(const std::string& phone) { phoneNumber = phone; }

    std::string getCity() { return city; }
    void setCity(const std::string& c) { city = c; }

    std::string getCountry() { return country; }
    void setCountry(const std::string& c) { country = c; }

    std::string getSchoolName() { return schoolName; }
    void setSchoolName(const std::string& name) { schoolName = name; }

    std::string getSchoolCity() { return schoolCity; }
    void setSchoolCity(const std::string& city) { schoolCity = city; }

    std::string getSchoolCountry() { return schoolCountry; }
    void setSchoolCountry(const std::string& country) { schoolCountry = country; }

    int getGroupNumber() { return groupNumber; }
    void setGroupNumber(int group) { groupNumber = group; }
};

class Point {
private:
    int x;
    int y;
    int z;
public:
    Point(): x(0), y(0), z(0) {}
    Point(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}

    void inputData() {
        std::cout << "x: "; std::cin >> x;
        std::cout << "y: "; std::cin >> y;
        std::cout << "z: "; std::cin >> z;
    }
    void outputData() {
        std::cout << "x: " << x;
        std::cout << "y: " << y;
        std::cout << "z: " << z;
    }
    bool saveToFile(const std::string& filename = "xyz.txt") const {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << x << " " << y << " " << z;
            outFile.close();
            std::cout << "Data saved to " << filename << std::endl;
            return 1;
        }
        else {
            std::cerr << "Unable to open the file for saving." << std::endl;
            return 0;
        }
    }
    bool loadFromFile(const std::string& filename = "xyz.txt") {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            inFile >> x >> y >> z;
            inFile.close();
            std::cout << "Data loaded from " << filename << std::endl;
            return 1;
        }
        else {
            std::cerr << "Unable to open the file for loading." << std::endl;
            return 0;
        }
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void setX(double xCoord) { x = xCoord; }
    void setY(double yCoord) { y = yCoord; }
    void setZ(double zCoord) { z = zCoord; }
};

void module1_IW();

#endif