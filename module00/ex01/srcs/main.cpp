/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:42:20 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/23 20:10:24 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

static std::string	displayPrompt(void);

int main(void)
{
	Phonebook	phonebook;
	std::string	command;

	do
	{
 		command = displayPrompt();
		if (command.empty() == true)
			return (0);
		if (command == "ADD")
			if (!phonebook.addContact())
				return (0);
		if (command == "SEARCH")
			if (!phonebook.displayContact())
				return (0);
	} while (command != "EXIT");
	return (0);
}

static std::string	displayPrompt(void)
{
	std::string command;
	do
	{
		std::cout << "ADD, SEARCH, EXIT: ";
		std::cin >> command;
		if (std::cin.eof())
			return ("");
	} while (command != "ADD" && command != "SEARCH" && command != "EXIT");
	return (command);
}
