#pragma once
#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string _name;
	int _hp;
	int _energy;
	unsigned int _dmg;

public:
	ClapTrap(std::string str);
	~ClapTrap();
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
