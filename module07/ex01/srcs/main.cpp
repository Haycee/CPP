/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 01:57:04 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	std::cout << std::endl << "====== TEST INT ======" << std::endl << std::endl;

	int	intArray[5] = {1, 2, 3, 4, 5};
	iter(intArray, 5, print<int>);

	std::cout << std::endl << "====== TEST DOUBLE ======" << std::endl << std::endl;

	double	doubleArray[2] = {1.2, 3.4};
	iter(doubleArray, 2, print<double>);

	std::cout << std::endl << "====== TEST STRING ======" << std::endl << std::endl;

	std::string strArray[3] = {"AB", "CD", "EF"};
	iter(strArray, 3, print<std::string>);

	return (0);
}
