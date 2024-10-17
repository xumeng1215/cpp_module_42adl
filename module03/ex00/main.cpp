#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap p1("CT0001");
	ClapTrap p2("CT0002");

	p1.attack("CT0002");
	p2.takeDamage(4);
	p2.beRepaired(3);
}