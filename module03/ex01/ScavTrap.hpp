#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	/* data */
public:
	ScavTrap (std::string str);
	~ScavTrap();
	void guardGate();
};
