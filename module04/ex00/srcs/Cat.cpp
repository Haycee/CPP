/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:54 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 19:18:32 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Cat::Cat()
{
	std::cout << "Cat Default constructor called" << std::endl;
	this->_type = "Cat";
	return;
}

Cat::Cat(Cat const & src) 
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called" << std::endl;
	return;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_type = rhs.getType();
	return (*this);
}
