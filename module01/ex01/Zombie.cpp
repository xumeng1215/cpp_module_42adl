#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "a Zombie is created." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie " << this->name << " is created." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is deleted." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}