#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "No idea";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

const std::string &Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	else
		throw std::out_of_range("Index out of range.");
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else
		throw std::out_of_range("Index out of range.");
}
