/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:12:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 23:10:19 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" << std::endl;
	return;
}

Brain::Brain(Brain const & src) 
{
	std::cout << "Brain Copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor called" << std::endl;
	return;
}

void	Brain::setIdea(int i, std::string str)
{
	if (i >= 0 && i < 100)
		this->_ideas[i] = str;
}

std::string	Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return (this->_ideas[i]);
	return (NULL);
}

Brain & Brain::operator=(Brain const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = rhs.getIdea(i);
	return (*this);
}
