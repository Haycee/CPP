/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:52 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/26 10:54:31 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Cat : public AAnimal
{
	public:

		Cat();
		Cat(Cat const & src);
		virtual ~Cat(void);

		void			setIdea(int i, std::string str);
		std::string		getIdea(int i) const;
		Brain &			getBrain(void) const;

		virtual void	makeSound(void) const;

		Cat &	operator=(Cat const & rhs);

	private:

		Brain	*_brain;
};
