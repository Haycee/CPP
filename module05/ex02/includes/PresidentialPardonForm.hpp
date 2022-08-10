/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 01:12:35 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/10 11:27:38 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "main.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		~PresidentialPardonForm(void);

		virtual void	execute(Bureaucrat const & executor) const;

	private :

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & rhs);
};
