#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria Type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria Assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "AMateria uses an unknown spell on " << target.getName() << std::endl;
}