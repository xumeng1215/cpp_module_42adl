#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called." << std::endl;
}
Brain::~Brain()
{
	std::cout << "Brain destructor called." << std::endl;
}
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = other;
}
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called." << std::endl;
	if (this == &other)
		return *this;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	return *this;
}

const std::string Brain::getIdea(unsigned int n) const
{
	if (n < 100)
		return this->ideas[n];
	else
		return NULL;
}

void Brain::setIdea(unsigned int n, std::string new_idea)
{
	if (n < 100)
		this->ideas[n] = new_idea;
	else
		std::cout << "wrong idea index number." << std::endl;
}
