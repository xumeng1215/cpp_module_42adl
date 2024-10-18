#include "Cat.hpp"

Cat::Cat(/* args */)
{
	std::cout << "Cat constructor called." << std::endl;
	type = "Cat";
	brain = new Brain();
	if (!brain)
	{
		std::cerr << "New brain failed." << std::endl;
		exit(1);
	}
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
	std::cout << "Cat copy constructor called."
			  << "Type is: " << type << std::endl;
	*this = other;
	this->type = other.type;
	this->brain = other.brain;
}

Cat &Cat::operator=(const Cat &other)
{
	if (this == &other)
		return *this;
	Animal::operator=(other);
	return *this;
	std::cout << "Cat " << type << " is assigned." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat " << type << " says: Meow!" << std::endl;
}

void Cat::getIdeas(void) const
{
	std::string idea;
	std::cout << "Here are ideas of a cat:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		idea = this->brain->getIdea(i);
		if (!idea.empty())
			std::cout << idea << std::endl;
	}
}

void Cat::setIdea(unsigned int n, std::string new_idea)
{
	this->brain->setIdea(n, new_idea);
}