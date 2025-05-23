#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cout << "Usage: ./PmergeMe [num1] [num2] ... [numN]" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			PmergeMe pmergeMe;
			pmergeMe.processInput(ac, av);
		}
		catch (const std::exception &e)
		{
			std::cerr << "ERROR: " << e.what() << std::endl;
			return 1;
		}
	}

	return 0;
}

// $> ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

// $> ./PmergeMe `jot -r 3000 1 100000 | tr '\n' ' '`