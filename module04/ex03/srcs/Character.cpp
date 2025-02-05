#include "Character.hpp"

Character::Character() : _name("Default")
{
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character Name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	std::cout << "Character Copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	*this = src;
}

Character::~Character()
{
	std::cout << "Character Destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

Character & Character::operator=(Character const & rhs)
{
	std::cout << "Character Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;

		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (rhs._inventory[i])
				this->_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return;
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		return;
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

AMateria* Character::getMateria(int idx) const
{
    if (idx < 0 || idx > 3)
        return NULL;
    return this->_inventory[idx];
}