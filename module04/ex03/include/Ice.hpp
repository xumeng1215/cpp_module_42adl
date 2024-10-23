#pragma once
#include <iostream>
#include <string>
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	// Ice(std::string const &type);
	~Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);

	Ice *clone() const;
	void use(ICharacter &target);
};