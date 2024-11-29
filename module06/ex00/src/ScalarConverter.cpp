#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _input("") {}

ScalarConverter::ScalarConverter(std::string const &input) : _input(input) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _input(other._input) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
		_input = other._input;
	return *this;
}

void ScalarConverter::convert(std::string const &input)
{
	int type;

	// type = checkInput(input);


	

}