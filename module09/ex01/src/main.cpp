#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"[expression]\"" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			RPN rpn;
			rpn.calculate(av[1]);
		}
		catch (const std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
			return 1;
		}
	}

	return 0;
}