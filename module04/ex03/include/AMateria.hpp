#pragma once
#include <iostream>
#include <string>
#include <ICharacter.hpp>

class AMateria
{
protected:
	std::string type;
public:
	AMateria(std::string const &type);
	virtual ~AMateria();
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);

	std::string const &getType() const;

	virtual AMateria* clone() const =0;
	virtual void use(ICharacter& target);


};

AMateria::AMateria(std::string const &type)
{
}

AMateria::~AMateria()
{
}
