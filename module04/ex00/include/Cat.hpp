#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
	// orthodox canonical form
	// constructor, destructor, copy constructor and operator=
	Cat();
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
};


