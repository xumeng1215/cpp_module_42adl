#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_source[i] = NULL;
	std::cout << "MateriaSource constructor called." << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		if (this->_source[i])
		{
			// std::cout << this->_source[i]->getType() << " is deleted." << std::endl;
			delete this->_source[i];
		}
}

MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource(other)
{
	for (int i = 0; i < 4; i++)
		if (other._source[i])
			this->_source[i] = other._source[i]->clone();
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_source[i])
				delete _source[i];
			if (other._source[i])
				_source[i] = other._source[i]->clone();
			else
				_source[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "The Materia is not valid for MateriaSource." << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_source[i] == NULL)
		{
			this->_source[i] = m;
			std::cout << "Materia " << this->_source[i]->getType() << " learned to source[" << i << "]." << std::endl;
			return;
		}
	}
	std::cout << "The MateriaSource is full." << std::endl;
	delete m;
	return;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (this->_source[i] && this->_source[i]->getType() == type)
			return this->_source[i]->clone();
	std::cout << "Can't create Materia, the type " << type << " is not valid." << std::endl;
	return 0;
}
