/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:14:44 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/27 15:14:06 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Intern::Intern()
{
	std::cout << "Intern Default constructor called" << std::endl;
	return;
}

Intern::Intern(Intern const & src) 
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Intern Destructor called" << std::endl;
	return;
}

int	Intern::_findForm(std::string form) const
{
	std::string forms[3] = {"presidential", "robotomy", "shrubbery"};
	std::string	str = form.substr(0, form.find(" "));

	for(int i = 0; i < 3; i++)
	{
		if (str == forms[i])
			return (i + 1);
	}
	return (0);
}

AForm	*Intern::makeForm(std::string form, std::string target)
{	
	int	formNumber = _findForm(form);

	switch (formNumber)
	{
		case 1:
			std::cout << "Intern creates PresidentialPardonForm form." << std::endl;
			return (new PresidentialPardonForm(target));
		case 2:
			std::cout << "Intern creates RobotomyRequestForm form." << std::endl;
			return (new RobotomyRequestForm(target));
		case 3:
			std::cout << "Intern creates ShrubberyCreationForm form." << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "This form does not exist." << std::endl;
			return (NULL);
	}
}

Intern & Intern::operator=(Intern const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}