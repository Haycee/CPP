/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:52:17 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/27 14:56:30 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Intern
{
	public:

		Intern();
		Intern(Intern const & src);
		~Intern(void);

		AForm	*makeForm(std::string form, std::string target);

		Intern &	operator=(Intern const & rhs);
	
	private:

		int		_findForm(std::string form) const;
};