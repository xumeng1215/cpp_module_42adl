#include "../include/Cat.hpp"

Cat::Cat(/* args */) : Animal(), brain(new Brain())
{
	std::cout << "Cat constructor called." << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called." << std::endl;
	delete brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called." << "Type is: " << type << std::endl;
	this->type = "Cat";
	if (other.brain)
		brain = new Brain(*other.brain);
	else
		brain = NULL;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called." << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		this->type = "Cat";
		if (brain)
			delete brain;
		if (other.brain)
			brain = new Brain(*other.brain);
		else
			brain = NULL;
	}
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat " << type << " says: Meow!" << std::endl;
}

const Brain *Cat::getBrain(void) const
{
	return brain;
}

void Cat::setBrain(const Brain &newBrain)
{
	if (brain)
		delete brain;
	brain = new Brain(newBrain);
}

std::string Cat::getBrainIdea(int index) const
{
	if (brain)
		return brain->getIdea(index);
	else
		return "Brain is NULL.";
}

void Cat::setBrainIdea(int index, const std::string &idea)
{
	if(brain)
		brain->setIdea(index, idea);
}
