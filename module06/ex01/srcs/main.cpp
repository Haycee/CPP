/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/29 11:12:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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
