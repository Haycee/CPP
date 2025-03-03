/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:54 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/07 19:57:19 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Cat::Cat()
	: _brain(new Brain())
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(Cat const & src) : AAnimal(src), _brain(new Brain())
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
	return;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

void	Cat::setIdea(int i, std::string str)
{
	this->_brain->setIdea(i, str);
}

std::string	Cat::getIdea(int i) const
{
	return (this->_brain->getIdea(i));
}

Brain &	Cat::getBrain(void) const
{
	return(*this->_brain);
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_type = rhs.getType();
	*(this->_brain) = rhs.getBrain();

	return (*this);
}
