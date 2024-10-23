#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	// AMateria();
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);

	std::string const &getType() const; // Returns the materia type
	void setType(std::string const &type);

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};


