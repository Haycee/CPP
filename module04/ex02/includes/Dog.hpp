/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:54 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/27 17:10:27 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Dog : public AAnimal
{
	public:

		Dog();
		Dog(Dog const & src);
		~Dog(void);

		void			setIdea(int i, const std::string str);
		std::string		getIdea(int i) const;
		virtual void	makeSound(void) const;

		Dog &	operator=(Dog const & rhs);

	private:

		Brain	*_brain;
};