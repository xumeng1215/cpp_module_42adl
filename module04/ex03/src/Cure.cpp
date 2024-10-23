#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

// Cure::Cure(std::string const &type) : AMateria(type)
// {
// 	this->_type = "Cure";
// 	std::cout << "Cure constructor called. " << this->_type << std::endl;
// }

Cure::~Cure()
{
	std::cout << "Cure destructor called. " << this->_type << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	this->_type = "Cure";
	std::cout << "Cure copy constructor called." << this->_type << std::endl;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this == &other)
		return *this;
	this->_type = other._type;
	std::cout << "Cure " << this->_type << " is assigned." << std::endl;
	return *this;
}

Cure *Cure::clone() const
{
	std::cout << "Cure clone function called." << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "Cure:* heals " << target.getName() << "'s wounds *" << std::endl;
}