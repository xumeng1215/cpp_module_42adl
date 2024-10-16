#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: name(name), weapon(NULL)
{
	std::cout << "HumanB " << this->name << " is created with no weapon"
			  << std::endl;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their "
			  << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	this->weapon = &newWeapon;
}