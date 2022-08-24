/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:18:56 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/24 10:38:40 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Zombie
{
	public:

		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);

	private:

		std::string	_name;
};
