/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:28:23 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/26 02:23:54 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Form::Form() : _name("Default"), _signGrade(1), _execGrade(1)
{
	std::cout << "Form Default constructor called" << std::endl;
	this->_isSigned = false;
	return;
}

Form::Form(std::string name, int signGrade, int execGrade) :
	_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "Form constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (signGrade > 150 || execGrade > 150)
	{
		throw GradeTooLowException();
	}
	this->_isSigned = false;
	return;
}

Form::Form(Form const & src) :
	_name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = src;
}

Form::~Form(void)
{
	std::cout << "Form Destructor called" << std::endl;
	return;
}

void	Form::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

int	Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

Form & Form::operator=(Form const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Form const & rhs)
{
	o << "Form: " << rhs.getName() << std::endl <<
		"Execution grade: " << rhs.getExecGrade() << std::endl <<
		"Signing grade: " << rhs.getSignGrade() << std::endl;
	if (rhs.getIsSigned() == false)
		o << "This form is not signed.";
	else 
		o << "This form is signed.";
	return (o);
}