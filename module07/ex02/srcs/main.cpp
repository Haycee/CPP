/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/04 02:53:58 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	Array<int>	emptyArray;


	Array<int>	intArray(3);
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	std::cout << "intArray[1]: " << intArray[1] << std::endl << std::endl;


	Array<int>	copyArray(intArray);	
	std::cout << "copyArray[1]: " << copyArray[1] << std::endl << std::endl;


	copyArray[1] = 4;
	std::cout << "intArray[1]: " << intArray[1] << std::endl;
	std::cout << "copyArray[1]: " << copyArray[1] << std::endl << std::endl;


	Array<double>	doubleArray(3);
	doubleArray[0] = 1.1;
	doubleArray[1] = 2.2;
	doubleArray[2] = 3.3;
	std::cout << "doubleArray[1]: " << doubleArray[1] << std::endl;
	std::cout << "doubleArray size: " << doubleArray.size() << std::endl << std::endl;

	try
	{
		std::cout << "doubleArray[5]: " << doubleArray[5] << std::endl << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	return (0);
}