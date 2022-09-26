/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:28:23 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/28 23:48:00 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

AForm::AForm()
	: _name("Default"), _signGrade(1), _execGrade(1), _target("Default")
{
	std::cout << "AForm Default constructor called" << std::endl;
	this->_isSigned = false;
	return;
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target)
	: _name(name), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
	std::cout << "AForm constructor called" << std::endl;
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

AForm::AForm(AForm const & src) :
	_name(src.getName()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = src;
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor called" << std::endl;
	return;
}

bool	AForm::checkExecGrade(Bureaucrat const & bureaucrat) const
{
	if (bureaucrat.getGrade() > this->_signGrade)
		return false;
	return true;
}

void	AForm::beSigned(Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

int	AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

std::string	AForm::getTarget(void) const
{
	return (this->_target);
}

AForm & AForm::operator=(AForm const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_isSigned = rhs.getIsSigned();
	this->_target = rhs.getTarget();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, AForm const & rhs)
{
	o << "Form: " << rhs.getName() << std::endl <<
		"Signing grade: " << rhs.getSignGrade() << std::endl <<
		"Execution grade: " << rhs.getExecGrade() << std::endl <<
		"Target: " << rhs.getTarget() << std::endl;
	if (rhs.getIsSigned() == false)
		o << "This form is not signed.";
	else 
		o << "This form is signed.";
	return (o);
}