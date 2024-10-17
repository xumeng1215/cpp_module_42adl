#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string str)
	: FragTrap(str), ScavTrap(str), _name(str)
{
	// this->_hp = FragTrap::_hp;
	// this->_energy = ScavTrap::_energy;
	std::cout << "DiamondTrap " << _name << " is constructed." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destructed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "who am I???" << this->_name << std::endl;
}
