/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:18 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/23 23:47:01 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	Animal* animal = j;
	animal->makeSound(); //will output the dog sound!

	std::cout << std::endl;

	WrongAnimal* wmeta = new WrongAnimal();
	WrongAnimal* wi = new WrongCat();

	wi->makeSound();
	wmeta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;

	std::cout << std::endl;

	delete wmeta;
	delete wi;

	return 0;
}
