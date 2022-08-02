/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 23:18:14 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 23:19:53 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "main.hpp"

class WrongCat : public WrongAnimal
{
	public:

		WrongCat();
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		virtual void	makeSound(void) const;

		WrongCat &	operator=(WrongCat const & rhs);
};