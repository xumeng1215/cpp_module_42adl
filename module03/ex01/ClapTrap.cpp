#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string str)
	: _name(str), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "ClapTrap " << this->_name << " is constructed." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " is destructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hp(other._hp), _energy(other._energy), _dmg(other._dmg)
{
	std::cout << "ClapTrap " << _name << " is copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this == &other)
		return *this;
	_name = other._name;
	_hp = other._hp;
	_energy = other._energy;
	_dmg = other._dmg;
	std::cout << "ClapTrap " << _name << " is assigned." << std::endl;
	return *this;
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

void ClapTrap::info()
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "HP: " << this->_hp << std::endl;
	std::cout << "ENERGY: " << this->_energy << std::endl;
	std::cout << "DMG: " << this->_dmg << std::endl;
}
