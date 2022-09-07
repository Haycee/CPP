/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:55 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/07 19:57:09 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Dog::Dog()
	: _brain(new Brain())
{
	std::cout << "Dog Default constructor called" << std::endl;
	this->_type = "Dog";
	return;
}

Dog::Dog(Dog const & src) 
	: _brain(new Brain())
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

Brain &	Dog::getBrain(void) const
{
	return(*this->_brain);
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_type = rhs.getType();
	*(this->_brain) = rhs.getBrain();

	return (*this);
}
