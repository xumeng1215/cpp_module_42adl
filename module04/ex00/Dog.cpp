#include "Dog.hpp"

Dog::Dog(/* args */)
{
	type = "Dog";
	std::cout << "Dog constructor called." << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called."
			  << "Type is: " << type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
	std::cout << "Dog " << type << " is assigned." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog " << type << " says: Woof!" << std::endl;
}