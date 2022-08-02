/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:46 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/06 20:44:57 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		horde[i] = Zombie(name);
	}
	return(horde);
}