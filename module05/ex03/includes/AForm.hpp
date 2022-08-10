/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:27:01 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/10 11:35:24 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Bureaucrat;

class AForm
{
	public:

		AForm();
		AForm(std::string name, int signGrade, int execGrade, std::string target);
		AForm(AForm const & src);
		virtual ~AForm(void);

		virtual void	execute(Bureaucrat const & executor) const = 0;
		bool			checkExecGrade(Bureaucrat const & bureaucrat) const;
		void			beSigned(Bureaucrat & bureaucrat);

		std::string	getName(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		int			getIsSigned(void) const;
		std::string	getTarget(void) const;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("This form is not signed.");
				}
		};

		class FailToOpenFileException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Couldn't open file.");
				}
		};

	private:

		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_isSigned;
		std::string			_target;

		AForm &	operator=(AForm const & rhs);
};

std::ostream &	operator<<(std::ostream & o, AForm const & rhs);
