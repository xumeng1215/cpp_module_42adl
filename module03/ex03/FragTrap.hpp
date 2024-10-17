#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string str);
	~FragTrap();
	void highFiveGuys(void);
	void attack(const std::string &target);
};
