/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:43:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/23 19:51:15 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void) : _index(0)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::setInfo(int i)
{
	this->_index = i;
	std::cout << "First Name: ";
	std::cin >> this->_firstName;
	if (std::cin.eof())
		return(0);
	std::cout << "Last Name: ";
	std::cin >> this->_lastName;
	if (std::cin.eof())
		return(0);
	std::cout << "_nickname: ";
	std::cin >> this->_nickname;
	if (std::cin.eof())
		return(0);
	std::cout << "Phone Number: ";
	std::cin >> this->_phoneNumber;
	if (std::cin.eof())
		return(0);
	std::cout << "Darkest Secret: ";
	std::cin >> this->_darkestSecret;
	if (std::cin.eof())
		return(0);
	return(1);
}

void	Contact::printInfo(void) const
{
	std::cout << "First Name:	" << this->_firstName << std::endl;
	std::cout << "Last Name:	" << this->_lastName << std::endl;
	std::cout << "nickname:	" << this->_nickname << std::endl;
	std::cout << "Phone Number:	" << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret:	" << this->_darkestSecret << std::endl;
}

std::string	Contact::_formatStr(std::string str) const
{
	if (str.length() < 10)
		while(str.length() != 10)
			str.insert(0, " ");
	if (str.length() > 10)
	{
		while(str.length() != 9)
			str.pop_back();
		str.insert(9, ".");
	}
	return (str);
}

void	Contact::printRecapInfo(void) const
{
	std::cout << "|          " << this->_index << "|";
	std::cout << _formatStr(this->_firstName) << "|";
	std::cout << _formatStr(this->_lastName) << "|";
	std::cout << _formatStr(this->_nickname) << "|" << std::endl;
}
