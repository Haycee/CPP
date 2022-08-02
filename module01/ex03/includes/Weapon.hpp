/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:51:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/07 19:13:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string&	getType(void);
		void				setType(std::string type);

	private:
		std::string	_type;
};