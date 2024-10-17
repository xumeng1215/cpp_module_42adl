#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap c1("CT0001");
	ClapTrap c2("CT0002");
	ScavTrap s1("ST0001");
	ScavTrap s2("ST0002");

	// c1.info();
	// s1.info();

	c1.attack("CT0002");
	c2.takeDamage(4);
	c2.beRepaired(3);

	s1.guardGate();
	s1.attack("ST0002");

}