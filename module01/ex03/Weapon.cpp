#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	if (!newType.empty())
		this->type = newType;
}
