/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:08:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 01:57:02 by agirardi         ###   ########lyon.fr   */
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
void	print(T & a)
{
	std::cout << a << std::endl;
}

template<typename T>
void	iter(T array[], int size, void f(T & a))
{
	for (int i = 0; i < size; i++)
	{
		f(array[i]);
	}
}