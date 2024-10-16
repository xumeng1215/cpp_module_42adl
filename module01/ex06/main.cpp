#include "Harl.hpp"

int mapping(char *str)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == str)
			return i;
	}
	return -1;
}

void harlSwitch(char *str, Harl &harl)
{
	int i = mapping(str);

	switch (i)
	{
	case 0:
		harl.complain("DEBUG");
	case 1:
		harl.complain("INFO");
	case 2:
		harl.complain("WARNING");
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int ac, char **av)
{
	Harl harl;

	if (ac != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		harlSwitch(av[1], harl);
	return 0;
}