#include "Character.hpp"

Character::Character(std::string const &name) : _name(name), _slot()
{
	std::cout << "Character constructor called. The new character is " << this->_name << "." << std::endl;
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
	if (!m)
	{
		std::cout << "Not a valid Materia." << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << "Materia " << m->getType() << " equiped at Character "
					  << this->_name << " slot [" << i << "]." << std::endl;
			return;
		}
	}
	std::cout << "The slot is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_slot[idx])
		{
			this->_slot[idx] = NULL;
			//TODO!!!!!LEAK???
			std::cout << "Character " << this->_name << " unequiped slot[" << idx << "]." << std::endl;
		}
		else
			std::cout << "Character " << this->_name << "slot[" << idx << "] is empty." << std::endl;
	}
	else
		std::cout << "The slot index is not valid." << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_slot[idx])
			this->_slot[idx]->use(target);
		else
			std::cout << "Character " << this->_name << " can't use it, slot[" << idx << "] is empty." << std::endl;
	}
	else
		std::cout << "The slot index is not valid." << std::endl;
}