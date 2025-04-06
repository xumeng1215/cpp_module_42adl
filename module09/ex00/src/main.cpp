#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (2 != ac)
	{
		std::cerr << "Usage: ./btc [file_name]" << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	btc.processInput(av[1]);

	return 0;
}