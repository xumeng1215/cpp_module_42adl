#include "ScalarConverter.hpp"

void put_nan(const std::string &input)
{
	(void)input;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void put_inf(const std::string &input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << std::endl;
	std::cout << "double: " << input << std::endl;
}

void put_char(const std::string &input)
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

void put_int(const std::string &input)
{
	long i = std::atol(input.c_str());

	// std::cout << "int: " << i << std::endl;

	std::cout << "char: ";
	if (i < 0 || i > 255)
		std::cout << "impossible" << std::endl;
	else
	{
		if (std::isprint(static_cast<int>(i)))
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	std::cout << "int: ";
	if (i > INT_MAX || i < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(i) << std::endl;

	std::cout << "float: " << static_cast<float>(i);
	if (i == static_cast<int>(i)) // Add ".0f" if the value is an integer
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(i);
	if (i == static_cast<int>(i))
		std::cout << ".0";
	std::cout << std::endl;
}

void put_float(const std::string &input)
{
	float f = std::atof(input.c_str());

	// std::cout << "float: " << f << "f" << std::endl;

	std::cout << "char: ";
	if (f < 0 || f > 255)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<int>(f)))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (f > INT_MAX || f < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;

	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(f);
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << std::endl;
}

void put_double(const std::string &input)
{
	double d = std::atof(input.c_str());

	// std::cout << "double: " << d << std::endl;

	std::cout << "char: ";
	if (d < 0 || d > 255)
		std::cout << "impossible" << std::endl;
	else if (std::isprint(static_cast<int>(d)))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;

	std::cout << "int: ";
	if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	std::cout << "float: ";
	if (d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << static_cast<float>(d);
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
}