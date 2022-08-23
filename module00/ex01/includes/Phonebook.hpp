/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:50:56 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/23 19:33:06 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Phonebook
{
	public:

		Phonebook(void);
		~Phonebook(void);

		int	addContact(void);
		int	displayContact(void);

	private:

		Contact	_contact[8];
		int		_contactCount;
		int		_contactIndex;

		int		_promptContactIndex(void);
};
