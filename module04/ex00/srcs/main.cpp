/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/07 16:10:32 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Animal* meta = new Animal();
	std::cout << std::endl;
	Animal* dog = new Dog();
	std::cout << std::endl;
	Animal* cat = new Cat();
	std::cout << std::endl;

	std::cout << "dog type: " << dog->getType() << " " << std::endl;
	dog->makeSound();
	std::cout << std::endl;
	std::cout << "cat type: " << cat->getType() << " " << std::endl;
	cat->makeSound();

	std::cout << std::endl << std::endl;

	Animal* animal = dog;
	animal->makeSound();

	std::cout << std::endl << std::endl << "============ WRONG CLASS TESTS ============ " << std::endl << std::endl << std::endl;

	WrongAnimal* wmeta = new WrongAnimal();
	std::cout << std::endl;
	WrongAnimal* wcat = new WrongCat();
	std::cout << std::endl;

	wcat->makeSound();
	wmeta->makeSound();

	std::cout << std::endl << std::endl;

	WrongCat catSound;
	std::cout << std::endl;
	catSound.makeSound();

	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl;

	delete wmeta;
	delete wcat;

	return 0;
}
