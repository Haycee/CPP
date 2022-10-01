/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/02 00:35:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	MutantStack<int>	mstack;

	std::cout << std::endl << "====== TEST BASE ======" << std::endl << std::endl;

	mstack.push(10);
	mstack.push(2);
	mstack.push(8);
	mstack.push(1);
	mstack.push(9);
	
	std::cout << "mstack top: " << mstack.top() << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl;

	mstack.pop();

	std::cout << "mstack top: " << mstack.top() << std::endl;
	std::cout << "mstack size: " << mstack.size() << std::endl << std::endl;


	std::cout << std::endl << "====== TEST ITERATORS ======" << std::endl << std::endl;

	MutantStack<int>::iterator	itBegin = mstack.begin();
	MutantStack<int>::iterator	itEnd = mstack.end();

	while (itBegin != itEnd)
	{
		std::cout << *itBegin << std::endl;
		++itBegin;
	}


	std::cout << std::endl << std::endl << "============================" << std::endl << std::endl;
	

	std::list<int>	lstack;

	std::cout << std::endl << "====== TEST BASE ======" << std::endl << std::endl;

	lstack.push_back(10);
	lstack.push_back(2);
	lstack.push_back(8);
	lstack.push_back(1);
	lstack.push_back(9);
	
	std::cout << "lstack top: " << lstack.back() << std::endl;
	std::cout << "lstack size: " << lstack.size() << std::endl;

	lstack.pop_back();

	std::cout << "lstack top: " << lstack.back() << std::endl;
	std::cout << "lstack size: " << lstack.size() << std::endl << std::endl;


	std::cout << std::endl << "====== TEST ITERATORS ======" << std::endl << std::endl;

	std::list<int>::iterator	ittBegin = lstack.begin();
	std::list<int>::iterator	ittEnd = lstack.end();

	while (ittBegin != ittEnd)
	{
		std::cout << *ittBegin << std::endl;
		++ittBegin;
	}

	std::cout << std::endl;

	return 0;
}
