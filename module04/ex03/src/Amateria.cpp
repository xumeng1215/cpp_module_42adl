#include "AMateria.hpp"
#include "Color.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Amateria " << this->_type << " is constructed." << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Amateria " << this->_type << " is destructed." << std::endl;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << "AMateria " << this->_type << " is copied." << std::endl;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this == &other)
		return *this;
	this->_type = other._type;
	std::cout << "AMateria " << this->_type << " is assigned." << std::endl;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "AMateria use function called. Type is " << this->_type << std::endl;
}
