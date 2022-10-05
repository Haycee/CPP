/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/05 11:14:21 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	std::cout << std::endl << "====== TEST VECTOR ======" << std::endl << std::endl;

	std::vector<int>	vect;

	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(6);

	std::vector<int>::iterator itrV = easyfind< std::vector<int> >(vect, 6);
	std::cout << "*itrV: " << *itrV << std::endl << std::endl;


	std::cout << std::endl << "====== TEST UNSORTED SET ======" << std::endl << std::endl;

	std::unordered_set<int>	uSet;

	uSet.insert(1);
	uSet.insert(3);
	uSet.insert(2);

	std::unordered_set<int>::iterator itrU = easyfind< std::unordered_set<int> >(uSet, 2);
	std::cout << "*itrU: " << *itrU << std::endl << std::endl;


	std::cout << std::endl << "====== TEST EXCEPTION ======" << std::endl << std::endl;

	try
	{
		itrU = easyfind< std::unordered_set<int> >(uSet, 7);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}

	return (0);
}
