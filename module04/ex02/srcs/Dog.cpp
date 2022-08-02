/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:55 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/24 17:32:43 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Dog::Dog()
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
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
	delete this->_brain;
	return;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

void	Dog::setIdea(int i, const std::string str)
{
	this->_brain->setIdea(i, str);
}

std::string	Dog::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_type = rhs.getType();
	for (int i = 0; i < 100; i++)
		this->setIdea(i, rhs.getIdea(i));
	return (*this);
}
