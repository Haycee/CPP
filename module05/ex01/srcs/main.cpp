/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 02:10:47 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	operator= pour Form ? (const data member)
	copy constructor pour Form ? (const data member)
	forward declarations ? (class Form; class Bureacrate; dans les .hpp)
*/

int	main(void)
{
	Bureaucrat	mark("Mark", 1);
	Form		severance("severance", 1, 1);
	
	std::cout << std::endl << mark << std::endl << std::endl;
	std::cout << severance << std::endl << std::endl;

	mark.signForm(severance);

	std::cout << std::endl << severance << std::endl << std::endl;


	Bureaucrat	Irving("Irving", 150);
	Form		severanceBis("severance", 1, 1);
	
	std::cout << std::endl << Irving << std::endl << std::endl;
	std::cout << severanceBis << std::endl << std::endl;

	Irving.signForm(severanceBis);

	std::cout << std::endl << severanceBis << std::endl << std::endl;

	return (0);
}