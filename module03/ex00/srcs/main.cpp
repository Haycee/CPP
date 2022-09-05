/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/05 14:23:59 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	ClapTrap test("A");
	test.attack("B");
	test.takeDamage(10);
	test.beRepaired(10);

	return (0);
}
