#pragma once
#include <iostream>
#include <string>

class ScalarConverter
{
private:
	std::string _input;
public:
	ScalarConverter();
	ScalarConverter(std::string const &input);
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	void convert();
};