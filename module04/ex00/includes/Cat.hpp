/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:52 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/26 10:51:45 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Cat : public Animal
{
	public:

		Cat();
		Cat(Cat const & src);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;

		Cat &	operator=(Cat const & rhs);
};
