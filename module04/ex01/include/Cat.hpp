#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat(/* args */);
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound(void) const;
	const Brain *getBrain(void) const;
	void setBrain(const Brain &newBrain);
	std::string getBrainIdea(int index) const;
	void setBrainIdea(int index, const std::string &idea);
};
