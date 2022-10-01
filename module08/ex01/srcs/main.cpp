/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 15:37:19 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{

	std::cout << std::endl << "====== TEST VALID ======" << std::endl << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span  : " << sp.longestSpan() << std::endl << std::endl;


	std::cout << std::endl << "====== TEST ADD RANGE ======" << std::endl << std::endl;

	std::vector<int> vec(20000, 200);

	vec[200] = 80;
	vec[0] = 30;
	vec[8000] = 5;
	
	Span spRange = Span(20000);
	spRange.addRange(vec.begin(), vec.end());
	std::cout << "Shortest span : " << spRange.shortestSpan() << std::endl;
	std::cout << "Longest span  : " << spRange.longestSpan() << std::endl << std::endl;


	std::cout << std::endl << "====== TEST EXCEPTION FULL ======" << std::endl << std::endl;

	Span spErrorSize = Span(3);

	spErrorSize.addNumber(22);
	spErrorSize.addNumber(3);
	spErrorSize.addNumber(98);

	try
	{
		spErrorSize.addNumber(922);
	}
	catch (Span::classFullException& e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}


	std::cout << std::endl << "====== TEST EXCEPTION INSUFFICIENT ELEMENTS ======" << std::endl << std::endl;

	Span spErrorFull = Span(1);

	spErrorFull.addNumber(0);
	try
	{
		std::cout << std::endl << spErrorFull.shortestSpan() << std::endl;
	}
	catch (Span::insufficientElementsException& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	return (0);
}