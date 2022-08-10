/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:42:27 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/10 11:36:33 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 72, 45, "Default")
{
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src)
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
	return;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (this->checkExecGrade(executor) == false)
		throw GradeTooLowException();
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	(void)rhs;
	return *this;
}
