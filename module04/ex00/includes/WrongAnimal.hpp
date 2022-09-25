/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:14:37 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/26 01:26:07 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void		makeSound(void) const;

		WrongAnimal &	operator=(WrongAnimal const & rhs);

	protected:

		std::string	_type;
};
