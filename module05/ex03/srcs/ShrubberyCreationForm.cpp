/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:48:28 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/10 11:36:32 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137, "Default")
{
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src)
	: AForm(src)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
	return;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream	outfile;

	if (this->getIsSigned() == false)
		throw FormNotSignedException();
	else if (this->checkExecGrade(executor) == false)
		throw GradeTooLowException();
	else
	{
		outfile.open(this->getTarget() + "_shrubbery");
		if (outfile.is_open())
		{
			outfile << "                                   # #### ####" << std::endl;
			outfile << "                                 ### \\/#|### |/####" << std::endl;
			outfile << "                                ##\\/#/ \\||/##/_/##/_#" << std::endl;
			outfile << "                              ###  \\/###|/ \\/ # ###" << std::endl;
			outfile << "                            ##_\\_#\\_\\## | #/###_/_####" << std::endl;
			outfile << "                           ## #### # \\ #| /  #### ##/##" << std::endl;
			outfile << "                            __#_--###`  |{,###---###-~" << std::endl;
			outfile << "                                      \\ }{" << std::endl;
			outfile << "                                       }}{" << std::endl;
			outfile << "                                       }}{" << std::endl;
			outfile << "                                  ejm  {{}" << std::endl;
			outfile << "                                 , -=-~{ .-^- _" << std::endl;
			outfile << "                                       `}" << std::endl;
			outfile << "                                        {" << std::endl;
			outfile.close();
		}
		else 
		{
			throw AForm::FailToOpenFileException();
		}
	}
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	(void)rhs;
	return *this;
}
