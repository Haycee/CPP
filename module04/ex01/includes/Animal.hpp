/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:13:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 23:44:58 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Animal
{
	public:

		Animal();
		Animal(Animal const & src);
		virtual ~Animal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

		Animal &	operator=(Animal const & rhs);

	protected:

		std::string	_type;
};
