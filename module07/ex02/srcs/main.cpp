/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 14:12:45 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	std::cout << std::endl << "====== TEST EMPTY ======" << std::endl << std::endl;

	Array<int>	emptyArray;


	std::cout << std::endl << "====== TEST INT ======" << std::endl << std::endl;

	Array<int>	intArray(3);
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	std::cout << "intArray[0]: " << intArray[0] << std::endl;
	std::cout << "intArray[1]: " << intArray[1] << std::endl;
	std::cout << "intArray[2]: " << intArray[2] << std::endl;


	std::cout << std::endl << "====== TEST FLOAT ======" << std::endl << std::endl;

	Array<float>	floatArray(3);
	floatArray[0] = 1.1;
	floatArray[1] = 2.2;
	floatArray[2] = 3.3;
	std::cout << "floatArray[0]: " << floatArray[0] << std::endl;
	std::cout << "floatArray[1]: " << floatArray[1] << std::endl;
	std::cout << "floatArray[2]: " << floatArray[2] << std::endl;


	std::cout << std::endl << "====== TEST COPY ======" << std::endl << std::endl;

	Array<int>	copyArray(intArray);
	std::cout << "intArray[1] : " << intArray[1] << std::endl;
	std::cout << "copyArray[1]: " << copyArray[1] << std::endl << std::endl;


	intArray[1] = 4;
	std::cout << "intArray[1] : " << intArray[1] << std::endl;
	std::cout << "copyArray[1]: " << copyArray[1] << std::endl;


	std::cout << std::endl << "====== TEST EXCEPTION ======" << std::endl << std::endl;

	Array<double>	doubleArray(3);
	std::cout << "doubleArray size: " << doubleArray.size() << std::endl;

	try
	{
		std::cout << "doubleArray[5]: " << doubleArray[5] << std::endl << std::endl << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl << "======================" << std::endl << std::endl;

	return (0);
}