#pragma once
#ifndef module1_hw2_h
#define module1_hw2_h
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

constexpr const char* fileName = "PhoneBook.txt";
constexpr const char* SEPARATOR = "---------------------------------------------------";

class Contact
{
private:
	char* fullName;
	std::string homePhone;
	std::string workPhone;
	std::string mobilePhone;
	std::string additionalInformation;
public:
	// Name specification is required 
	Contact(const char* name, const char* home = nullptr,
		const char* work = nullptr, const char* mobile = nullptr, std::string add = "")
	{
		if (name) {
			fullName = new char[strlen(name) + 1];
			strcpy_s(fullName, strlen(name) + 1, name);
		}
		else {
			fullName = nullptr;
		}
		if (home != nullptr) homePhone = home;
		if (work != nullptr) workPhone = work;
		if (mobile != nullptr) mobilePhone = mobile;
		additionalInformation = add;
	}
	Contact() {
		fullName = nullptr;
	}
	~Contact()
	{
		//if (fullName != nullptr) delete[] fullName;
	}

	// Setters
	void setFullName(const char* name) {
		if (fullName) {
			delete[] fullName; // Deallocate previous memory
		}
		fullName = new char[strlen(name) + 1];
		strcpy_s(fullName, strlen(name) + 1 ,name);
	}
	void setHomePhone(std::string home) { homePhone = home; }
	void setWorkPhone(std::string work) { workPhone = work; }
	void setMobilePhone(std::string mobile) { mobilePhone = mobile; }
	void setAdditionalInformation(std::string info) { additionalInformation = info; }
	// Getters
	char* getFullName() const { return fullName; }
	std::string getHomePhone() const { return (!homePhone.empty()) ? homePhone: ""; }
	std::string getWorkPhone() const { return (!workPhone.empty()) ? workPhone : ""; }
	std::string getMobilePhone() const { return (!mobilePhone.empty()) ? mobilePhone : ""; }
	std::string getAdditionalInformation() const { return additionalInformation; }
};

void module1_hw2();

class PhoneBook
{
private:
	std::vector<Contact> list;

public:
	void push_back(Contact& cons) {
		list.push_back(cons);
	}

	template<typename... Args>
	void push_back(Contact& cons, Args... args) {
		list.push_back(cons);
		push_back(args...);
	}

	PhoneBook() {
		pull();
	}
	template<typename... Args>
	PhoneBook(Contact& cons, Args... args) {
		pull();
		push_back(cons, args...);
	}
	~PhoneBook() {
		push();
	}

	void createContact();
	void findIndices(std::vector<size_t>& matchingIndicies, std::string fullName = "");
	void deleteContact();
	void pull();
	void push();
	void display(size_t index = -1);
};

#endif


