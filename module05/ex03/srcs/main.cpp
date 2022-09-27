/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/27 15:19:21 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Bureaucrat	mark("Mark", 1);
	Intern		someRandomIntern;
	
	std::cout << std::endl << std::endl << "============ VALID FORM TEST ============ " << std::endl << std::endl << std::endl;

	AForm*	form;
	form = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl;

	mark.signForm(*form);
	mark.executeForm(*form);
	
	std::cout << std::endl;
	delete form;

	std::cout << std::endl << std::endl << "============ INVALID FORM TEST ============ " << std::endl << std::endl << std::endl;

	form = someRandomIntern.makeForm("severence request", "Bender");
	std::cout << std::endl;

	return (0);
}
