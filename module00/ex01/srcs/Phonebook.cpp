/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:43:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/01 15:51:27 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Phonebook::Phonebook(void)
{
	this->_contact_count = 0;
	this->_contact_index = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	return;
}

int	Phonebook::add_contact(void)
{
	if (!this->_contact[this->_contact_index].set_info(this->_contact_index))
		return (0);
	this->_contact_index += 1;
	if (this->_contact_index > 7)
		this->_contact_index = 0;

	if (this->_contact_count < 7)
		this->_contact_count += 1;
	return (1);
}

int	Phonebook::_prompt_contact_index(void)
{
	std::string	contact;
	int			index;
	
	do
	{
		std::cout << "Select contact: ";
		std::cin >> contact;
		if (std::cin.eof())
			return(-1);
		std::istringstream(contact) >> index;
	} while(index < 0 || index >= this->_contact_count);
	return (index);
}

int	Phonebook::display_contact(void)
{
	for (int i = 0; i < this->_contact_count; i++)
		this->_contact[i].print_recap_info();
	int index = _prompt_contact_index();
	if (index == -1)
		return (0);
	this->_contact[index].print_info();
	return (1);
}
