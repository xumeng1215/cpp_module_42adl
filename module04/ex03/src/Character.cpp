#include "Character.hpp"

Character::Character(std::string const &name) : _name(name)
{
	std::cout << "The new character " << this->_name << " is constructed." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		this->_slot[i] = NULL;
		this->_bag[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << "Character " << this->_name << " will be destructed." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i])
			delete this->_slot[i];
		if (this->_bag[i])
			delete this->_bag[i];
	}
}
Character::Character(const Character &other)
	: ICharacter(other), _name(other._name), _slot(), _bag()
{
	for (int i = 0; i < 4; i++)
	{
		if (other._slot[i])
			this->_slot[i] = other._slot[i]->clone();
		if (other._bag[i])
			this->_bag[i] = other._bag[i]->clone();
	}
}

Character &Character::operator=(const Character &other)
{
	if (this == &other)
		return *this;
	this->_name = other.getName();
	for (int i = 0; i < 4; i++)
	{
		if (other._slot[i])
			this->_slot[i]->setType(other._slot[i]->getType());
		if (other._bag[i])
			this->_bag[i]->setType(other._bag[i]->getType());
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
		std::cout << this->_name << " can't equip this. Not a valid Materia." << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_slot[i] == NULL)
		{
			this->_slot[i] = m;
			std::cout << this->_name << " equipted Materia " << m->getType() << " at slot [" << i << "]." << std::endl;
			return;
		}
	}
	std::cout << this->_name << "can't equip this, the slot is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		if (this->_slot[idx])
		{
			std::cout << this->_name << " unequiped " << this->_slot[idx]->getType() << " at slot[" << idx << "]." << std::endl;
			if (this->_bag[idx] != NULL)
				delete this->_bag[idx];
			this->_bag[idx] = this->_slot[idx];
			this->_slot[idx] = NULL;
		}
		else
			std::cout << "Character can't unequip. " << this->_name << " slot[" << idx << "] is empty." << std::endl;
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