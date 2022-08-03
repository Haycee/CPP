/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:08:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 16:41:24 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <float.h>

template<typename T>
void	swap(T & a, T & b)
{
	T	buffer;

	buffer = a;
	a = b;
	b = buffer;
}

template<typename T>
T	min(T a, T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename T>
T	max(T a, T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}