#include "ScalarConverter.hpp"
#include <limits.h>
#include <cfloat>
#include <string>

static bool isChar(const std::string &input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
		return true;
	if (input.length() == 2 && input[0] == '\'' && input[2] == '\'')
		return true;
	return false;
}

static bool isInt(const std::string &input)
{
	size_t i = 0;

	if (input.empty())
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length())
	{
		if (!std::isdigit(input[i]))
			return false;
		i++;
	}
	if (input.length() > 11 || (input.length() == 11 && (input[0] != '-' && input[0] != '+')))
		return false;
	return true;
}

static bool isDouble(const std::string &input)
{
	size_t i = 0;
	int dot = 0;

	if (input.empty())
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length())
	{
		if (input[i] == '.')
			dot++;
		else if (!std::isdigit(input[i]))
			return false;
		i++;
	}
	if (dot > 1)
		return false;
	if (input.length() > 11 || (input.length() == 11 && (input[0] != '-' && input[0] != '+')))
		return false;
	return true;
}

static bool isFloat(const std::string &input)
{
	size_t i = 0;
	size_t dot = 0;

	if (input.empty())
		return false;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length() - 1)
	{
		if (input[i] == '.')
			dot++;
		else if (!std::isdigit(input[i]))
			return false;
		i++;
	}
	if (dot > 1 || input[i] != 'f')
		return false;
	return true;
}

static void put_nan(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input;
	if (input[input.length() - 1] != 'f')
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: ";
	if (input[input.length() - 1] == 'f')
		std::cout << "nan";
	else
		std::cout << input;
	std::cout << std::endl;
}

static void put_inf(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << std::endl;
	std::cout << "double: " << input << std::endl;
}

static void put_char(const std::string &input)
{
	char c;

	if (input.length() == 1)
		c = input[0];
	else
		c = input[1];
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void put_int(const std::string &input)
{
	long i = std::atol(input.c_str());

	std::cout << "char: ";
	if (i < 0 || i > 255)
		std::cout << "impossible" << std::endl;
	else
	{
		if (std::isprint(i))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	std::cout << "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(i) << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void put_float(const std::string &input)
{
	float f = std::atof(input.c_str());
	std::cout << "char: ";
	if (std::isprint(f))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f  << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void put_double(const std::string &input)
{
	double d = std::atof(input.c_str());
	std::cout << d << std::endl;
	std::cout << "char: ";
	if (std::isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (d > INT_MAX || d < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d > FLT_MAX || d < -FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

static scalarType getType(const std::string &str)
{
	if (str == "nan" || str == "nanf")
		return NAN_;
	if (str == "-inf" || str == "+inf" || str == "-inff" || str == "+inff")
		return INF;
	else if (isChar(str))
		return CHAR;
	else if (isInt(str))
		return INT;
	else if (isDouble(str))
		return DOUBLE;
	else if (isFloat(str))
		return FLOAT;
	else
		return INVALID;
}

void ScalarConverter::convert(std::string const &input)
{
	scalarType type = getType(input);

	switch (type)
	{
	case NAN_:
		std::cout << "Type is NAN." << std::endl;
		put_nan(input);
		break;
	case INF:
		std::cout << "Type is INF." << std::endl;
		put_inf(input);
		break;
	case CHAR:
		std::cout << "Type is CHAR." << std::endl;
		put_char(input);
		break;
	case INT:
		std::cout << "Type is INT." << std::endl;
		put_int(input);
		break;
	case FLOAT:
		std::cout << "Type is FLOAT." << std::endl;
		put_float(input);
		break;
	case DOUBLE:
		std::cout << "Type is DOUBLE." << std::endl;
		put_double(input);
		break;
	case INVALID:
		std::cout << "Invalid value. Try again." << std::endl;
		break;
	}
}