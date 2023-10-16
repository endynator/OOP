#ifndef module1_hw1_h
#define module1_hw1_h
#include <stdexcept>
#include <iostream>

class Fraction 
{
private:
	double numerator;
	double denominator;
public:
	Fraction(double num, double den)
		: numerator(num), denominator(den) {
		if (den == 0)
			throw std::invalid_argument("Denominator cannot be zero.");
	}
	// Getters/Setters

	double getNumerator() const {
		return numerator;
	}
	double getDenominator() const {
		return denominator;
	}
	double getDecimal_fraction(double num = 0, double den = 0) const {
		if (!num && !den) return numerator / denominator;
		else if (!num && den) return numerator / den;
		else if (num && !den) return num / denominator;
		else return num / den;
	}

	void setNumerator(double num) {
		numerator = num;
	}

	void setDenominator(double den) {
		denominator = den;
	}

	// Other stuff

	double addition(double a) const {
		return numerator + a * denominator;
	}

	double subtraction(double a) const {
		return numerator - a * denominator;
	}

	double multiplication(double a) const {
		return a * numerator;
	}
	
	double devision(double a) const {
		return denominator * a;
	}

	// Class-to-Class interactions

	Fraction addition(Fraction f) {
		double d2 = f.denominator, d1 = denominator;
		double n1 = numerator, n2 = f.numerator;
		if (d1 != d2) {
			d1 *= f.denominator; n1 *= f.denominator;
			d2 *= denominator; n2 *= denominator;
		}
		Fraction result(n1 + n2, d1);
		return result;
	}

	Fraction subtraction(Fraction f) {
		double d2 = f.denominator, d1 = denominator;
		double n1 = numerator, n2 = f.numerator;
		if (d1 != d2) {
			d1 *= f.denominator; n1 *= f.denominator;
			d2 *= denominator; n2 *= denominator;
		}
		Fraction result(n1 - n2, d1);
		return result;
	}

	Fraction multiplication(const Fraction& f) const {
		Fraction result(numerator * f.numerator, denominator * f.denominator);
		return result;
	}

	Fraction devision(const Fraction& f) const {
		Fraction result(numerator * f.denominator, denominator * f.numerator);
		return result;
	}

};

void module1_hw1();

#endif