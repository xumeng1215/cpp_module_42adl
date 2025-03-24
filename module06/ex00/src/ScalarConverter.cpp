#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string const &input)
{
	scalarType type = getType(input);

	switch (type)
	{
	case NAN_:
		put_nan(input);
		break;
	case INF:
		put_inf(input);
		break;
	case CHAR:
		put_char(input);
		break;
	case INT:
		put_int(input);
		break;
	case FLOAT:
		put_float(input);
		break;
	case DOUBLE:
		put_double(input);
		break;
	case INVALID:
		std::cout << "Invalid input value. Try again." << std::endl;
		break;
	}
}

ScalarConverter::ScalarConverter() : _input("")
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string const &input) : _input(input)
{
	std::cout << "Parameter Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : _input(other._input)
{
	std::cout << "Copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}
