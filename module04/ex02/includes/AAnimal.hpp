/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:13:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/27 17:12:24 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class AAnimal
{
	public:

		AAnimal();
		AAnimal(AAnimal const & src);
		virtual ~AAnimal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

		AAnimal &	operator=(AAnimal const & rhs);

	protected:

		std::string	_type;
};
