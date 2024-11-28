#pragma once
#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
	// orthodox canonical form
	// constructor, destructor, copy constructor and operator= 
	Animal();
	virtual ~Animal();
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);

	// getters and setters
	std::string getType(void) const;
	
	// makeSound method, virtual
	virtual void makeSound(void) const;
};

