#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(/* args */);
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
};


