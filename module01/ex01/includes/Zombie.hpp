/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:14 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 01:39:27 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Zombie
{
	public:

		Zombie();
		Zombie(std::string name);
		~Zombie(void);

		void announce(void);

	private:

		std::string	_name;
};