/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 18:32:01 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	https://stackoverflow.com/questions/1282914/pass-pointer-to-template-function-as-function-argument
*/

int main(void)
{
	int	intArray[5] = {1, 2, 3, 4, 5};
	iter<int>(intArray, 5, print<int>);

	double	doubleArray[2] = {1.2, 3.4};
	iter<double>(doubleArray, 2, print<double>);

	std::string strArray[3] = {"AB", "CD", "EF"};
	iter<std::string>(strArray, 3, print<std::string>);

	return (0);
}