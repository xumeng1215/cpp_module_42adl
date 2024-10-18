#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */)
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called." << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called."
			  << "Type is: " << type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	if (this == &other)
		return *this;
	WrongAnimal::operator=(other);
	std::cout << "WrongCat " << type << " is assigned." << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat " << type << " says: I want coffee!" << std::endl;
}