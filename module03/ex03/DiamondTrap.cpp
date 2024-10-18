#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string str)
	: ClapTrap(str + "_clap_name"),
	  FragTrap(str),
	  ScavTrap(str),
	  _name(str)
{
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_dmg = FragTrap::_dmg;
	// this->_dmg = 1000000;
	std::cout << "DiamondTrap " << _name << " is constructed." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destructed." << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "who am I???" << this->_name << std::endl;
	std::cout << "who am I as a ClapTrap???" << ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
