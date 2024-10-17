#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap ,public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap(std::string str);
	~DiamondTrap();
	void whoAmI();
	void attack(const std::string &target);

};

