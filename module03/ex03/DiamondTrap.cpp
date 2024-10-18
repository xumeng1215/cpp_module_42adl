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
	std::cout << "DiamondTrap " << _name << " is constructed." << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " is destructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " is copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this == &other)
		return *this;
	FragTrap::operator=(other);
	ScavTrap::operator=(other);
	_name = other._name;
	std::cout << "DiamondTrap " << _name << " is assigned." << std::endl;
	return *this;
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
