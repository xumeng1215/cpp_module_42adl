#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>

enum scalarType
{
	NAN_,
	INF,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

class ScalarConverter
{
private:
	
	const std::string _input;
	
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(std::string const &input);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);

	
	public:
	static void convert(std::string const &input);
	
};
