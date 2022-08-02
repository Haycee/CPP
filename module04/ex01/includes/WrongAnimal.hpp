/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:14:37 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 23:45:04 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class WrongAnimal
{
	public:

		WrongAnimal();
		WrongAnimal(WrongAnimal const & src);
		virtual ~WrongAnimal(void);

		std::string	getType(void) const;
		void		makeSound(void) const;

		WrongAnimal &	operator=(WrongAnimal const & rhs);

	protected:

		std::string	_type;
};
