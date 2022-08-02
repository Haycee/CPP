/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:48:08 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/08 14:53:55 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	this->_weapon = NULL;
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << "attacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
