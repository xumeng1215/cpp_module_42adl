#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	int num = 4;
	std::string name = "MMMMJ";

	Zombie *horde = zombieHorde(num, name);
	int i = 0;
	while (i < num)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}
