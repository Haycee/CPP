/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/07 15:28:44 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	std::cout << "==== LEAK TEST ====" << std::endl;

	AAnimal	*objAnimal[4];

	objAnimal[0] = new Cat();
	objAnimal[1] = new Cat();
	objAnimal[2] = new Dog();
	objAnimal[3] = new Dog();

	for (int i = 0; i < 4; i++)
		delete objAnimal[i];

	std::cout << "===================" << std::endl << std::endl;

	std::cout << "==== TEST COPY ====" << std::endl;

	Cat cat;
	Cat cat2;

	cat.setIdea(0, "1");
	cat2.setIdea(0, "2");
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl << std::endl;
	
	cat = cat2;
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl << std::endl;
	
	cat2.setIdea(0, "3");
	std::cout << cat.getIdea(0) << std::endl;
	std::cout << cat2.getIdea(0) << std::endl << std::endl;
}
