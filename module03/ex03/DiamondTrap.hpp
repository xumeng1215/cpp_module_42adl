#pragma once
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap ,public ScavTrap
{
private:
	std::string _name;
public:
	DiamondTrap(/* args */);
	~DiamondTrap();
	void whoAmI();
};

DiamondTrap::DiamondTrap(/* args */)
{
}

DiamondTrap::~DiamondTrap()
{
}
