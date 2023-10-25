#include "../headers/homework2.h"

#include <iostream>
#include <string>

//3rd party libraries
//#include <fmt/format.h>
//#include <fmt/ostream.h>

void module1_hw2() {
	PhoneBook book;
	std::vector<size_t> results;
	while (true) {
		unsigned int v;
		std::cout << "Choose an option: \n"
			<< "1. Create contact\n"
			<< "2. Delete contact\n"
			<< "3. Find contact\n"
			<< "4. Display contacts\n"
			<< "5. Exit\n";
		std::cin >> v;
		switch (v)
		{
		case 1:
			book.createContact();
			break;
		case 2:
			book.deleteContact();
			break;
		case 3:
			book.findIndices(results);
			std::cout << "Matching contacts: \n";
			for (auto& i : results) {
				book.display(i);
				}
			break;
		case 4:
			book.display();
			break;
		default:
			return;
		}
	}
}

