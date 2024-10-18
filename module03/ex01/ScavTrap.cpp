#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string str) : ClapTrap(str)
{
	_hp = 100;
	_energy = 50;
	_dmg = 20;

	std::cout << "ScavTrap " << this->_name << " is constructed." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " is destructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " is copied." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this == &other)
		return *this;
	ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << " is assigned." << std::endl;
	return *this;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is in GateKeeper mode." << std::endl;
}
