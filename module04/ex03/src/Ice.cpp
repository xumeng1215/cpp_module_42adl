#include "Ice.hpp"
Ice::Ice() : AMateria("Ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(std::string const &type) : AMateria(type)
{
	this->_type = "Ice";
	std::cout << "Ice constructor called. " << this->_type << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called. " << this->_type << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	this->_type = "Ice";
	std::cout << "Ice copy constructor called." << this->_type << std::endl;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this == &other)
		return *this;
	AMateria::operator=(other);
	std::cout << "Ice " << this->_type << " is assigned." << std::endl;
	return *this;
}

Ice *Ice::clone() const
{
	std::cout << "Ice clone function called." << std::endl;
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "Ice:* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}