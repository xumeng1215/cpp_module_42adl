#include "../include/Dog.hpp"

Dog::Dog(/* args */) : Animal(), brain(new Brain())
{
	std::cout << "Dog constructor called." << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete brain;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << "Type is: " << type << std::endl;
	this->type = "Dog";
	if (other.brain)
		brain = new Brain(*other.brain);
	else
		brain = NULL;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = "Dog";
		if (brain)
			delete brain;
		if (other.brain)
			brain = new Brain(*other.brain);
		else
			brain = NULL;
	}
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog " << type << " says: Woof!" << std::endl;
}

const Brain *Dog::getBrain(void) const
{
	return brain;
}

void Dog::setBrain(const Brain &newBrain)
{
	if (brain)
		delete brain;
	brain = new Brain(newBrain);
}

std::string Dog::getBrainIdea(int index) const
{
	if (brain)
		return brain->getIdea(index);
	else
		return "Brain is NULL.";
}

void Dog::setBrainIdea(int index, const std::string &idea)
{
	if(brain)
		brain->setIdea(index, idea);
}