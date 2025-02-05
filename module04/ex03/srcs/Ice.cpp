#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(Ice const & src) : AMateria(src)
{
	std::cout << "Ice Copy constructor called" << std::endl;
	*this = src;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

Ice & Ice::operator=(Ice const & rhs)
{
	std::cout << "Ice Assignment operator called" << std::endl;
  (void)rhs;
	return (*this);
}

AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}