/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/27 15:30:42 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	std::cout << std::endl << std::endl << "============ VALID TEST ============ " << std::endl << std::endl << std::endl;

	Bureaucrat	mark("Mark", 1);
	Form		severance("severance", 1, 1);
	
	std::cout << std::endl << mark << std::endl << std::endl;
	std::cout << severance << std::endl << std::endl;

	mark.signForm(severance);

	std::cout << std::endl << severance << std::endl << std::endl;

	std::cout << std::endl << std::endl << "============ INVALID TEST ============ " << std::endl << std::endl << std::endl;

	Bureaucrat	Irving("Irving", 150);
	Form		severanceBis("severance", 1, 1);
	
	std::cout << std::endl << Irving << std::endl << std::endl;
	std::cout << severanceBis << std::endl << std::endl;

	Irving.signForm(severanceBis);

	std::cout << std::endl << severanceBis << std::endl << std::endl;

	return (0);
}