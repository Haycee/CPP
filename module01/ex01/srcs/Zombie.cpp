/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:44:59 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/08 14:57:41 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie Default constructor called" << std::endl;
	return;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie constructor called" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie destructor called" << std::endl;
	return;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
