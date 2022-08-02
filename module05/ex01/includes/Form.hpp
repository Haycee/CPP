/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:27:01 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/28 23:45:26 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Bureaucrat;

class Form
{
	public:

		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const & src);
		~Form(void);

		void		beSigned(Bureaucrat & bureaucrat);
		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		int			getIsSigned(void) const;

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

		Form &	operator=(Form const & rhs);

	private:

		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;
};

std::ostream &	operator<<(std::ostream & o, Form const & rhs);