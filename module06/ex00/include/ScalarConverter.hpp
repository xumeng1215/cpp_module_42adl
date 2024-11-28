#pragma once
#include <iostream>
#include <string>

class ScalarConverter
{
private:
	std::string _input;
	int _type;
	
	char _char;
	int _int;
	float _float;
	double _double;
	
	// ScalarConverter();
	// ~ScalarConverter();
	// ScalarConverter(std::string const &input);
	// ScalarConverter(const ScalarConverter &other);
	// ScalarConverter &operator=(const ScalarConverter &other);
public:
	static void convert(std::string const &input);
};