#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

