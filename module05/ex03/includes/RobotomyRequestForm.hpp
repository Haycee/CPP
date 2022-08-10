/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:41:40 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/10 11:36:59 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		~RobotomyRequestForm(void);

		virtual void	execute(Bureaucrat const & executor) const;

	private :

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & rhs);
};
