/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:55 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 19:18:46 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(Dog const & src) 
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog Destructor called" << std::endl;
	return;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}
