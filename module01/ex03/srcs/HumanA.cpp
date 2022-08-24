/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:12:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/24 14:21:36 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

HumanA::HumanA(std::string name, Weapon & weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructor called" << std::endl;
	return;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor called" << std::endl;
	return;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
