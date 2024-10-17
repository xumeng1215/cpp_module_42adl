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

void FragTrap::highFiveGuys()
{
	std::cout << "FragTrap HighFiveGuys!!!" << std::endl;
}