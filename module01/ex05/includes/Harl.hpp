/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:45:14 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/09 17:56:55 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Harl
{
	public:

		Harl(void);
		~Harl(void);

		void complain(std::string level);

	private:

		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};