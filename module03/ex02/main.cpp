#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap c1("CT0001");
	ScavTrap s1("ST0001");
	FragTrap f1("FT0001");

	// c1.info();
	// s1.info();

	c1.attack("CT0002");
	c1.takeDamage(4);
	c1.beRepaired(3);

	s1.guardGate();
	s1.attack("ST0002");
	s1.info();

	f1.highFiveGuys();
	f1.attack("FT0002");
	f1.info();
}