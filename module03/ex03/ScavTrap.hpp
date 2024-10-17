#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string str);
	~ScavTrap();
	void guardGate();
	void attack(const std::string &target);
};
