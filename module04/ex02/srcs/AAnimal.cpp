/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:12:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/27 17:07:38 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal Default constructor called" << std::endl;
	this->_type = "Default";
	return;
}

AAnimal::AAnimal(AAnimal const & src) 
{
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal Destructor called" << std::endl;
	return;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}
