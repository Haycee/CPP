/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:42:27 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/10 11:41:13 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45, "Default")
{
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: AForm(src)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
	return;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (this->checkExecGrade(executor) == false)
		throw GradeTooLowException();
	else
	{
		std::cout << "*drilling noises*" << std::endl;
		srand(time(NULL));
		if ((rand() % 2) == 0)
			std::cout << this->getTarget() << " has been robotomized." << std::endl;
		else
			std::cout << "The robotomy has failed." << std::endl;
	}
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	(void)rhs;
	return *this;
}
