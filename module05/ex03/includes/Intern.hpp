/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:52:17 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/31 19:39:18 by agirardi         ###   ########lyon.fr   */
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

		int		findForm(std::string form) const;
		AForm	*makeForm(std::string form, std::string target) const;

		Intern &	operator=(Intern const & rhs);
};