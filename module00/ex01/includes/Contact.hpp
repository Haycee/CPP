/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:50:56 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/23 19:32:19 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		int		setInfo(int i);
		void	printInfo(void) const;
		void	printRecapInfo(void) const;

	private:

		int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		std::string	_formatStr(std::string str) const;
};
