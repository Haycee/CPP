/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:53:24 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 15:05:12 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

template <typename T>
typename T::iterator	easyfind(T & container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);

	if (it == container.end())
		throw std::invalid_argument("num was not found.");
	else
		return (it);
}	
