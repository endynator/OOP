#pragma once
#include <iostream>

class string
{
	size_t lenght;
	char* value;
public:
	string(const char* v, size_t l) : lenght(l), value{ new char[l] } { }
};