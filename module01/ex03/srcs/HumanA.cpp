/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:12:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/08 14:45:32 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << "attacks with their " << _weapon.getType() << std::endl;
}
