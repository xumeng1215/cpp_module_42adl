#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string _name;
	int _hp;
	int _energy;
	unsigned int _dmg;

public:
	ClapTrap(std::string str) : _name(str), _hp(10), _energy(10), _dmg(0)
	{
		std::cout << "ClapTrap " << _name << " is constructed." << std::endl;
	}
	~ClapTrap()
	{
		std::cout << "ClapTrap " << _name << " is destructed." << std::endl;
	}
};

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(std::string str) : ClapTrap(str)
	{			   // Call ClapTrap constructor
		_hp = 100; // Initialize additional members
		_energy = 100;
		_dmg = 30;
		std::cout << "FragTrap " << _name << " is constructed." << std::endl;
	}
};

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap(std::string str) : ClapTrap(str)
	{			   // Call ClapTrap constructor
		_hp = 100; // Initialize additional members
		_energy = 50;
		_dmg = 20;
		std::cout << "ScavTrap " << _name << " is constructed." << std::endl;
	}
};

class DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string _name; // DiamondTrap's own name

public:
	DiamondTrap(std::string str)
		: ClapTrap(str), FragTrap(str), ScavTrap(str), _name(str)
	{ // This line initializes ClapTrap via FragTrap and ScavTrap
		std::cout << "DiamondTrap " << _name << " is constructed." << std::endl;
	}
	~DiamondTrap()
	{
		std::cout << "DiamondTrap " << _name << " is destructed." << std::endl;
	}
};

int main()
{
	DiamondTrap diamondTrap("DT-1");
	return 0;
}
