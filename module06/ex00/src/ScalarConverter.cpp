#include "ScalarConverter.hpp"

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