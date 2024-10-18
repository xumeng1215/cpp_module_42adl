#include "Animal.hpp"

Animal::Animal() : type("Animal_Default_Type")
{
	std::cout << "Animal constructor called." << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called."
			  << "Type is: " << type << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
	std::cout << "Animal " << type << " is assigned." << std::endl;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal " << type << " is making sound." << std::endl;
}
