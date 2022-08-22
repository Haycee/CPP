/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/22 11:42:29 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	operator= ne copie pas toutes les informations
	Laisser _target dans AForm ou le placer dans les sous classes ?
*/

int	main(void)
{
	srand(time(NULL));

	Bureaucrat				mark("Mark", 1);
	ShrubberyCreationForm	shrubForm("Helly");
	
	std::cout << std::endl << mark << std::endl;
	std::cout << std::endl << shrubForm << std::endl << std::endl;
	mark.executeForm(shrubForm);
	std::cout << std::endl;
	mark.signForm(shrubForm);
	std::cout << std::endl;
	mark.executeForm(shrubForm);
	std::cout << std::endl;

	Bureaucrat			irving("Irving", 1);
	RobotomyRequestForm	robotForm("Dylan");

	std::cout << std::endl << irving << std::endl;
	std::cout << std::endl << robotForm << std::endl << std::endl;
	irving.signForm(robotForm);
	std::cout << std::endl;
	irving.executeForm(robotForm);
	std::cout << std::endl;

	Bureaucrat				dylan("Dylan", 1);
	PresidentialPardonForm	PresForm("Mark");

	std::cout << std::endl << dylan << std::endl;
	std::cout << std::endl << PresForm << std::endl << std::endl;
	dylan.signForm(PresForm);
	std::cout << std::endl;
	dylan.executeForm(PresForm);
	std::cout << std::endl;

	return (0);
}
