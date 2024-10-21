#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	AMateria *_slot[4];
	std::string _name;

public:
	Character(std::string const &name);
	~Character();
	Character(const Character &other);
	Character &operator=(const Character &other);

	std::string const &getName() const;
	void setName(std::string const &name);
	
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};
