#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria* _templates[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const & src);
	virtual ~MateriaSource();

	MateriaSource & operator=(MateriaSource const & rhs);

	virtual void learnMateria(AMateria* materia);
	virtual AMateria* createMateria(std::string const & type);
};