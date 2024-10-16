#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
	: name(name), weapon(weapon)
{
	std::cout << "HumanA " << this->name << " is created with weapon "
			  << this->weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their "
			  << this->weapon.getType() << std::endl;
}