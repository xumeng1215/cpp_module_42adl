#include "FragTrap.hpp"

FragTrap::FragTrap(std::string str) : ClapTrap(str)
{
	_hp = 100;
	_energy = 100;
	_dmg = 30;
	std::cout << "FragTrap " << this->_name << " is constructed." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " is destructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " is copied." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	std::cout << "FragTrap " << _name << " is assigned." << std::endl;
	return *this;
}

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap HighFiveGuys!!!" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	std::cout << "FragTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_dmg << " points of damage!"
			  << std::endl;
}