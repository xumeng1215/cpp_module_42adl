#include "Cat.hpp"

Cat::Cat(/* args */)
{
	type = "Cat";
	std::cout << "Cat constructor called." << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called."
			  << "Type is: " << type << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
	std::cout << "Cat " << type << " is assigned." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat " << type << " says: Meow!" << std::endl;
}