/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:50:56 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/01 15:59:33 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		int		set_info(int i);
		void	print_info(void) const;
		void	print_recap_info(void);

	private:
		int			_index;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		std::string	_format_str(std::string str);
};
