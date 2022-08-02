/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/02 17:19:02 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	struct forme canonique ?
	https://stackoverflow.com/questions/1845482/what-is-uintptr-t-data-type/1846648#1846648
	https://www.oreilly.com/library/view/understanding-and-using/9781449344535/ch01.html
*/

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);

int main(void)
{
	Data coord;

	uintptr_t	serial = serialize(&coord);
	std::cout << "serial: " << serial << std::endl;

	Data	*data = deserialize(serial);
	data->x = 10;
	data->y = 20;
	data->z = 30;
	std::cout << "x: " << data->x << std::endl;
	std::cout << "y: " << data->y << std::endl;
	std::cout << "z: " << data->z << std::endl;

	return 0;
}

uintptr_t	serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}