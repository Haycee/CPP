/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:12:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/06 13:20:09 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "main.hpp"
ClapTrap::ClapTrap()
	: _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src) 
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
	return;
}

std::string		ClapTrap::getName(void) const
{
	return this->_name;
}

int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int	ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		if (this->_attackDamage == 0)
			std::cout << "ClapTrap ";
		else
			std::cout << "ScavTrap ";
		std::cout << this->_name << " attacks " << target <<  ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_attackDamage == 0)
		std::cout << "ClapTrap ";
	else
		std::cout << "ScavTrap ";
	std::cout << this->_name << " is loosing " << amount << " hit points!" << std::endl;
	this->_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		if (this->_attackDamage == 0)
			std::cout << "ClapTrap ";
		else
			std::cout << "ScavTrap ";
		std::cout << this->_name << " has regenerated " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();

	return (*this);
}
