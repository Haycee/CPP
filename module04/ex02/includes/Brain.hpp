/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:13:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/07 15:19:01 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Brain
{
	public:

		Brain();
		Brain(Brain const & src);
		~Brain(void);

		void		setIdea(int i, std::string str);
		std::string	getIdea(int i) const;
		Brain &		getBrain(void) const;
	
		Brain &	operator=(Brain const & rhs);

	protected:

		std::string _ideas[100];
};
