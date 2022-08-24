/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:57:09 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/24 10:57:34 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class HumanA
{
	public:

		HumanA(std::string name, Weapon & weapon);
		~HumanA(void);

		void	attack(void);

	private:

		std::string	_name;
		Weapon &	_weapon;
};
