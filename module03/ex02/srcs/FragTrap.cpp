/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:03:13 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 15:48:33 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(std::string name):ClapTrap(name)
{
	std::cout << "FragTrap Name constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const & src) 
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " is requesting high fives!" << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_hitPoints = rhs.getHitPoints();
	this->_energyPoints = rhs.getEnergyPoints();
	this->_attackDamage = rhs.getAttackDamage();
	return (*this);
}
