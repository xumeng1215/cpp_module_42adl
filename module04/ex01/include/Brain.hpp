#pragma once
#include <iostream>
#include <string>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain &operator=(const Brain &other);

	const std::string getIdea(unsigned int n) const;
	void setIdea(unsigned int n, std::string new_idea);
};
