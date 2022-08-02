/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:52 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/28 03:25:19 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Bureaucrat
{
	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		void		promote(void);
		void		demote(void);
		std::string	getName(void) const;
		int			getGrade(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("The requested grade is too high.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("The requested grade is too low.");
				}
		};

		Bureaucrat &	operator=(Bureaucrat const & rhs);

	private:

		std::string	_name;
		int			_grade;
};

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs);