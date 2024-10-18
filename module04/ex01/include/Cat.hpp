#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <cstdlib>

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
	void getIdeas(void) const;
	void setIdea(unsigned int n, std::string new_idea);
};
