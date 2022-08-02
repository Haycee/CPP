/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:50:56 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/01 15:51:32 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "main.hpp"

class Phonebook
{
	public:
	
		Phonebook(void);
		~Phonebook(void);

		int	add_contact(void);
		int	display_contact(void);

	private:
		Contact	_contact[8];
		int		_contact_count;
		int		_contact_index;
		int		_prompt_contact_index(void);
};
