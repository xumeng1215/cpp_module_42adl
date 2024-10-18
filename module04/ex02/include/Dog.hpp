#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

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
	const Brain *getBrain(void) const;
	void setBrain(const Brain &newBrain);
	std::string getBrainIdea(int index) const;
	void setBrainIdea(int index, const std::string &idea);
};
