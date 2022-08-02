/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:51:54 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/30 00:38:18 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	this->_name = "Default";
	this->_grade = 150;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) 
{
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
	return;
}

void	Bureaucrat::promote(void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::demote(void)
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(AForm & form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't signed the " << form.getName() << " form because his grade is too low." << std::endl;
		return;
	}
	std::cout << "Bureaucrat " << this->_name << " signed the " << form.getName() << " form." << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
	}
	catch (AForm::FormNotSignedException & e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't execute the " << form.getName() << " form because it is not signed." << std::endl;
		return;
	}
	catch (AForm::GradeTooLowException & e)
	{
		std::cout << "Bureaucrat " << this->_name << " couldn't execute the " << form.getName() << " form because his grade is too low." << std::endl;
		return;
	}
	catch (AForm::FailToOpenFileException & e)
	{
		std::cout << "Failed to create the file." << std::endl;
		return;
	}
	std::cout << "Bureaucrat " << this->_name << " executed the " << form.getName() << " form." << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_name = rhs.getName();
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}