#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdlib>

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog(/* args */);
	~Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);

	void makeSound(void) const;
	void outputBrain(void) const;
	void setIdea(unsigned int n, std::string new_idea);
};
