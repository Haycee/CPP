/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:43:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/01 15:44:56 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::set_info(int i)
{
	this->_index = i;
	std::cout << "First Name: ";
	std::cin >> this->_first_name;
	if (std::cin.eof())
		return(0);
	std::cout << "Last Name: ";
	std::cin >> this->_last_name;
	if (std::cin.eof())
		return(0);
	std::cout << "_nickname: ";
	std::cin >> this->_nickname;
	if (std::cin.eof())
		return(0);
	std::cout << "Phone Number: ";
	std::cin >> this->_phone_number;
	if (std::cin.eof())
		return(0);
	std::cout << "Darkest Secret: ";
	std::cin >> this->_darkest_secret;
	if (std::cin.eof())
		return(0);
	return(1);
}

void	Contact::print_info(void) const
{
	std::cout << "First Name:	" << this->_first_name << std::endl;
	std::cout << "Last Name:	" << this->_last_name << std::endl;
	std::cout << "nickname:	" << this->_nickname << std::endl;
	std::cout << "Phone Number:	" << this->_phone_number << std::endl;
	std::cout << "Darkest Secret:	" << this->_darkest_secret << std::endl;
}

std::string	Contact::_format_str(std::string str)
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

void	Contact::print_recap_info(void)
{
	std::cout << "|          " << this->_index << "|";
	std::cout << _format_str(this->_first_name) << "|";
	std::cout << _format_str(this->_last_name) << "|";
	std::cout << _format_str(this->_nickname) << "|" << std::endl;
}
