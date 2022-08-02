/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 15:49:49 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	ClapTrap a("A");
	a.attack("B");
	a.takeDamage(9);
	a.beRepaired(9);

	std::cout << std::endl << std::endl;

	ScavTrap c("C");
	c.attack("A");
	a.takeDamage(20);
	a.beRepaired(20);
	c.guardGate();

	std::cout << std::endl << std::endl;

	FragTrap e("E");
	e.attack("C");
	c.takeDamage(30);
	c.beRepaired(30);
	e.highFivesGuys();

	std::cout << std::endl << std::endl;

	return 0;
}
