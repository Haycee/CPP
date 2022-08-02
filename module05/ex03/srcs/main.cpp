/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/31 19:38:47 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	copy constructor & operator= ?
*/

int	main(void)
{
	Bureaucrat mark("Mark", 1);
	Intern someRandomIntern;
	
	std::cout << std::endl;

	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	std::cout << std::endl;

	mark.signForm(*rrf);
	mark.executeForm(*rrf);
	
	std::cout << std::endl;
	delete rrf;
	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("severence request", "Bender");
	std::cout << std::endl;

	return (0);
}