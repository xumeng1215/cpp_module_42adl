#include "Dog.hpp"

Dog::Dog(/* args */)
{
	std::cout << "Dog constructor called." << std::endl;
	type = "Dog";
	brain = new Brain();
	if (!brain)
	{
		std::cerr << "New brain failed." << std::endl;
		exit(1);
	}
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called." << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called."
			  << "Type is: " << type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
	std::cout << "Dog " << type << " is assigned." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog " << type << " says: Woof!" << std::endl;
}

void Dog::outputBrain(void) const
{
	std::string idea;
	std::cout << "Dog is thinking:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea = this->brain->getIdea(i);
		if (!idea.empty())
			std::cout << idea << std::endl;
	}
}

void Dog::setIdea(unsigned int n, std::string new_idea)
{
	this->brain->setIdea(n, new_idea);
}