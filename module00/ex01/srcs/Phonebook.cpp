/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:43:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/23 20:22:27 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Phonebook::Phonebook(void) : _contactCount(0), _contactIndex(0)
{
	return;
}

Phonebook::~Phonebook(void)
{
	return;
}

int	Phonebook::addContact(void)
{
	if (this->_contactIndex == 8)
		this->_contactIndex = 0;
	
	if (!this->_contact[this->_contactIndex].setInfo(this->_contactIndex))
		return (0);

	this->_contactIndex++;
	
	if (this->_contactCount < 8)
		this->_contactCount++;
	return (1);
}

int	Phonebook::_promptContactIndex(void)
{
	std::string	contactNumber;
	int			index;

	index = -1;
	do {
		std::cout << "Select contact: ";
		std::cin >> contactNumber;
		if (std::cin.eof())
			return(-1);
		if (contactNumber.length() == 1 && contactNumber[0] >= '0' && contactNumber[0] <= '9')
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
	{
		this->_contact[i].printRecapInfo();
	}
	int index = this->_promptContactIndex();
	if (index == -1)
		return (0);
	this->_contact[index].printInfo();
	return (1);
}
