#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_templates[i] = NULL;
	*this = src;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i])
			delete this->_templates[i];
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
	std::cout << "MateriaSource Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_templates[i])
			{
				delete this->_templates[i];
				this->_templates[i] = NULL;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs._templates[i])
				this->_templates[i] = rhs._templates[i]->clone();
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] == NULL)
		{
			this->_templates[i] = materia->clone();
      delete materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_templates[i] && this->_templates[i]->getType() == type)
			return this->_templates[i]->clone();
	}
	return 0;
}