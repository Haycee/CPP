/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 01:04:37 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/07 15:21:50 by agirardi         ###   ########lyon.fr   */
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

		void			setIdea(int i, std::string str);
		std::string		getIdea(int i) const;
		Brain &			getBrain(void) const;

		virtual void	makeSound(void) const;

		Cat &	operator=(Cat const & rhs);

	private:

		Brain	*_brain;
};
