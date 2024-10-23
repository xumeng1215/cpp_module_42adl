#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	// Cure(std::string const &type);
	~Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);

	Cure *clone() const;
	void use(ICharacter &target);
};