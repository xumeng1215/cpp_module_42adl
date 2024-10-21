#include "MateriaSource.hpp"

MateriaSource::MateriaSource(/* args */) : _source()
{
	std::cout << "MateriaSource constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_source[i])
			delete this->_source[i];
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
	for (int i = 0; i < 4; i++)
		if (other._source[i])
			this->_source[i] = other._source[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	// TODO: insert return statement here
}

void MateriaSource::learnMateria(AMateria *)
{
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	return nullptr;
}
