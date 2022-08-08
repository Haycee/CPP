/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:43:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/08 10:41:39 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Phonebook::Phonebook(void)
{
	this->_contactCount = 0;
	this->_contactIndex = 0;
	return;
}

Phonebook::~Phonebook(void)
{
	return;
}

int	Phonebook::addContact(void)
{
	if (!this->_contact[this->_contactIndex].setInfo(this->_contactIndex))
		return (0);

	this->_contactIndex += 1;
	if (this->_contactIndex > 7)
		this->_contactIndex = 0;

	if (this->_contactCount < 7)
		this->_contactCount += 1;
	return (1);
}

int	Phonebook::_promptContactIndex(void)
{
	std::string	contactNumber;
	int			index;

	do	{
		std::cout << "Select contact: ";
		std::cin >> contactNumber;
		if (std::cin.eof())
			return(-1);
		std::istringstream(contactNumber) >> index;
	} while(index < 0 || index >= this->_contactCount);
	return (index);
}

int	Phonebook::displayContact(void)
{
	if (this->_contactCount == 0)
	{
		std::cout << "There is no contact in this phonebook." << std::endl;
		return (1);
	}
	for (int i = 0; i < this->_contactCount; i++)
		this->_contact[i].printRecapInfo();
	int index = _promptContactIndex();
	if (index == -1)
		return (0);
	this->_contact[index].printInfo();
	return (1);
}
