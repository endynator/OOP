#include <iostream>
#include <string>
#include <iomanip>
#include "../headers_modules/module1_hw1.h"

void module1_hw1() {
	// See the declaration of "Fraction" at "../headers_modules/module1_hw1 .h"
	Fraction fraction(3, 5);
	Fraction interfierer(6, 7);

	// Expected result: 13/5
	std::cout << "Addition: " << fraction.addition(2) << "/"
		<< fraction.getDenominator() << std::endl;
	
	// Expected result: -22/5
	std::cout << "Subtraction: " << fraction.subtraction(5) << "/"
		<< fraction.getDenominator() << std::endl;

	// Expected result: 15/5
	std::cout << "Multiplication: " << fraction.multiplication(5) << "/"
		<< fraction.getDenominator() << std::endl;

	// Expected result 3/10
	std::cout << "Devision: " << fraction.getNumerator() << "/"
		<< fraction.devision(2) << std::endl << std::endl;

	// Expected result 51/35
	Fraction result = fraction.addition(interfierer);
	std::cout << "Addition: " << result.getNumerator() << "/"
		<< result.getDenominator() << std::endl;

	// Expected result -9/35
	result = fraction.subtraction(interfierer);
	std::cout << "Substraction: " << result.getNumerator() << "/" 
		<< result.getDenominator() << std::endl;

	// Expected result 18/35
	result = fraction.multiplication(interfierer);
	std::cout << "Multiplication: " << result.getNumerator() << "/"
		<< result.getDenominator() << std::endl;

	// Expected result 21/30
	result = fraction.devision(interfierer);
	std::cout << "Devision: " << result.getNumerator() << "/"
		<< result.getDenominator() << std::endl;
}

