/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:52 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 19:19:03 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Cat : public Animal
{
	public:

		Cat();
		Cat(Cat const & src);
		~Cat(void);

		virtual void	makeSound(void) const;

		Cat &	operator=(Cat const & rhs);
};