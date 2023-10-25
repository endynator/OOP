#include "headers/homework2.h"
#include <iostream>
#include <string>

void PhoneBook::display(size_t index) {
	if (index == -1) {
		for (auto& acc : list) {
			std::cout << "Full Name: " << acc.getFullName() << std::endl;
			std::cout << "Home Phone: " << acc.getHomePhone() << std::endl;
			std::cout << "Work Phone: " << acc.getWorkPhone() << std::endl;
			std::cout << "Mobile Phone: " << acc.getMobilePhone() << std::endl;
			std::cout << "Additional info: " << acc.getAdditionalInformation() << std::endl << SEPARATOR << std::endl;
		}
	}
	else {
		std::cout << "Full Name: " << list[index].getFullName() << std::endl;
		std::cout << "Home Phone: " << list[index].getHomePhone() << std::endl;
		std::cout << "Work Phone: " << list[index].getWorkPhone() << std::endl;
		std::cout << "Mobile Phone: " << list[index].getMobilePhone() << std::endl;
		std::cout << "Additional info: " << list[index].getAdditionalInformation() << std::endl << SEPARATOR << std::endl;
	}
}

// Saves indexes of matching name in given vector 
void PhoneBook::findIndices(std::vector<size_t>& matchingIndices, std::string fullName) {
	if (fullName == "") {
		std::cout << "Name: "; 
		std::cin.ignore();
		std::getline(std::cin, fullName);
	}
	matchingIndices.clear();

	for (size_t i = 0; i < list.size(); i++) {
		if (list[i].getFullName() != nullptr &&
			std::strcmp(list[i].getFullName(), fullName.c_str()) == 0) {
			matchingIndices.push_back(i);
		}
	}
}

void PhoneBook::deleteContact() {
	std::string fullName;
	std::cout << "Name: "; std::getline(std::cin, fullName);
	// Vector to store indices of matching contacts
	std::vector<size_t> matchingIndices;

	findIndices(matchingIndices, fullName);

	if (matchingIndices.empty()) {
		std::cout << "No contacts with the given fullName found." << std::endl;
		return;
	}

	// If there are multiple matches, ask the user to choose one
	if (matchingIndices.size() > 1) {
		std::cout << "Multiple contacts found with the given full name. Please choose one:" << std::endl;
		for (size_t i = 0; i < matchingIndices.size(); i++) {
			std::cout << i + 1 << ". ";
			display(matchingIndices[i]);
		}

		int choice;
		do {
			std::cout << "Enter the number of the contact to remove: ";
			std::cin >> choice;
		} while (choice < 1 || choice > static_cast<int>(matchingIndices.size()));

		// Remove the chosen contact
		list.erase(list.begin() + matchingIndices[choice - 1]);
	}
	else {
		// If there's only one match, remove it directly
		list.erase(list.begin() + matchingIndices[0]);
	}

	std::cout << "Contact(s) with the given fullName removed." << std::endl;
}


void PhoneBook::createContact() {

	std::string* s = new std::string[5];

	std::cout << "Disclaimer: Every parameter has its symbol limits.\n"
		<< "Every symbol that passed the limit won't be written e.g. 'name' has limit of 20.\n"
		<< "Please, write ONLY DIGITS when specifying phone data,\n"
		<< "Otherwise, the data may be written incorrectly\n";
	std::cout << "Name (required): ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, s[0]);
	std::cout << "Home Phone (optional): ";
	std::getline(std::cin, s[1]);
	std::cout << "Work Phone (optional): ";
	std::getline(std::cin, s[2]);
	std::cout << "Mobile Phone (optional): ";
	std::getline(std::cin, s[3]);
	std::cout << "Additional Information (optional) (limitless): ";
	std::getline(std::cin, s[4]);

	if (s[0].empty()) {
		std::cerr << "Name is required.\n";
		delete[] s;
		return;
	}
	Contact result(s[0].c_str());
	for (size_t i = 1; i < 5; i++) {
		if (s[i].length() == 0 || s[i].empty()) { continue; }
		switch (i)
		{
		case 1:
			result.setHomePhone(s[i].c_str());
			break;
		case 2:
			result.setWorkPhone(s[i].c_str());
			break;
		case 3:
			result.setMobilePhone(s[i].c_str());
			break;
		case 4:
			result.setAdditionalInformation(s[i]);
			break;
		default:
			break;
		}
	}
	push_back(result);

	std::cout << "Success\n";

	delete[] s;
}

void PhoneBook::push() {
	std::ofstream file(fileName);

	if (file.is_open()) {
		for (auto& contact : list) {
			std::string s(contact.getFullName());
			file << "fullName : " << s << "\n";
			file << "homePhone : " << contact.getHomePhone() << "\n";
			file << "workPhone : " << contact.getWorkPhone() << "\n";
			file << "mobilePhone : " << contact.getMobilePhone() << "\n";
			file << "addInfo : " << contact.getAdditionalInformation() << "\n";
			file << SEPARATOR << std::endl;
		}
		file.close();
	}
}

void PhoneBook::pull() {
	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cerr << "Unable to open the file.\n";
		return;
	}

	std::vector<std::string> lines;
	std::string line;
	Contact currentContact;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
	if (lines.empty()) return;
	for (auto& line : lines) {
		size_t pos = line.find(": ");
		if (pos != std::string::npos) {
			std::string key = line.substr(0, pos);
			std::string value = line.substr(pos + 2);
			if (key == "fullName ") {
				currentContact.setFullName(value.c_str());
			}
			else if (key == "homePhone ") {
				if (!value.empty()) currentContact.setHomePhone(value);
			}
			else if (key == "workPhone ") {
				if (!value.empty()) currentContact.setWorkPhone(value);
			}
			else if (key == "mobilePhone ") {
				if (!value.empty()) currentContact.setMobilePhone(value);
			}
			else if (key == "addInfo ") {
				if (!value.empty()) currentContact.setAdditionalInformation(value);
			}
		}
		if (line == SEPARATOR) {
			list.push_back(currentContact);
			//currentContact = Contact();
		}
	}

	file.close();
}
