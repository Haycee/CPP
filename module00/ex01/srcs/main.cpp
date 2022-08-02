/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:42:20 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 01:12:46 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static std::string	prompt_contact(void);

int main(void)
{
	Phonebook phonebook;
	std::string command;

	while (command == "EXIT")
	{
 		command = prompt_contact();
		if (command.empty() == true)
			return (0);
		if (command == "ADD")
		{
			if (!phonebook.add_contact())
				return (0);
		}
		else
			if (!phonebook.display_contact())
				return (0);
	}
	return (0);
}

static std::string	prompt_contact(void)
{
	std::string command;
	do
	{
		std::cout << "ADD, SEARCH, EXIT: ";
		std::cin >> command;
		if (std::cin.eof())
			return ("");
	} while (command.compare("ADD") != 0 && command.compare("SEARCH") != 0 && command.compare("EXIT") != 0);
	return (command);
}
