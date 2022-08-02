/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:52 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/27 17:10:22 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Cat : public AAnimal
{
	public:

		Cat();
		Cat(Cat const & src);
		~Cat(void);

		void			setIdea(int i, std::string str);
		std::string		getIdea(int i) const;
		virtual void	makeSound(void) const;

		Cat &	operator=(Cat const & rhs);

	private:

		Brain	*_brain;
};