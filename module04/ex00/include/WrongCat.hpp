#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(/* args */);
	~WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);

	void makeSound(void) const;
};


