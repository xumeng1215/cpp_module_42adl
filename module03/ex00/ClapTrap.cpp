#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str)
	: _name(str), _hp(10), _energy(10), _dmg(0)
{
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_dmg << " points of damage!"
			  << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take "
			  << amount << " points of damage!" << std::endl;
	this->_hp = this->_hp - amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " get "
			  << amount << " points of repair!" << std::endl;
	this->_hp = this->_hp + amount;
}
