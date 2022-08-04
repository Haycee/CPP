/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 13:53:24 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/04 17:24:48 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

template <typename T>
typename T::iterator	easyfind(T & container, int num)
{
	typename T::iterator itr;

	itr = std::find(container.begin(), container.end(), num);
	if (itr == container.end())
		throw std::invalid_argument("num was not found.");
	return (itr);
}