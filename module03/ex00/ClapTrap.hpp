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
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
