/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/05 02:27:43 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	Constructeur par default privé ?
*/

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;


	std::vector<int> vec(20000, 200);
	vec[200] = 80;
	vec[0] = 30;
	vec[8000] = 5;
	
	Span spRange = Span(20000);
	spRange.addRange(vec.begin(), vec.end());
	std::cout << spRange.shortestSpan() << std::endl;
	std::cout << spRange.longestSpan() << std::endl << std::endl;


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
		std::cout << e.what() << std::endl;
	}


	Span spErrorFull = Span(1);
	spErrorFull.addNumber(0);
	try
	{
		std::cout << spErrorFull.shortestSpan() << std::endl;
	}
	catch (Span::insufficientElementsException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}