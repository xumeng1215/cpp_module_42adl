#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal_Default_Type")
{
	std::cout << "WrongAnimal constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called."
			  << "Type is: " << type << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	std::cout << "WrongAnimal " << type << " is assigned." << std::endl;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal " << type << " made a speech." << std::endl;
}
