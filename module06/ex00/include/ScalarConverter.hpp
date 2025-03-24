#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include <limits.h>
#include <cfloat>
#include <string>

#include <cmath>
#include <limits>
#include <iostream>

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

scalarType getType(const std::string &str);
void put_nan(const std::string &input);
void put_inf(const std::string &input);
void put_char(const std::string &input);
void put_int(const std::string &input);
void put_float(const std::string &input);
void put_double(const std::string &input);
