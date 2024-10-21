#include "Character.hpp"

Character::Character(std::string const &name) : _name("default_name"), _slot()
{
	std::cout << "Character constructor called." << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_slot[i])
			delete this->_slot[i];
}
Character::Character(const Character &other) : ICharacter(other), _name(other._name), _slot()
{
	for (int i = 0; i < 4; i++)
		if (other._slot[i])
			this->_slot[i] = other._slot[i]->clone();
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return *this;
	this->_name = other.getName();
	for (int i = 0; i < 4; i++)
		if (other._slot[i])
		{
			delete this->_slot[i];
			this->_slot[i] = other._slot[i]->clone();
		}
	return *this;
}

const std::string &Character::getName() const
{
	return this->_name;
}

void Character::setName(std::string const &name)
{
	this->_name = name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m != NULL && this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << "Materia " << m->getType() << " equiped at Character "
					  << this->_name << "'s slot [" << i << "]." << std::endl;
			return;
		}
	}
	std::cout << "There's no slot for a new Materia." << std::endl;
}
