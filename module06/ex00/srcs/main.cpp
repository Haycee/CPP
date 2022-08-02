/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/02 04:05:16 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	Gérer +a || -a || 4fffffff ?
*/

int main(int argc, char *argv[])
{
	std::string	literal = argv[1];
	Converter	*converter;

	if (argc != 2)
	{
		std::cout << "Usage: ./convert literal" << std::endl;
		return (0);
	}

	try
	{
		converter = new Converter(literal);
	}
	catch (Converter::ParsingException &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	converter->printChar();
	converter->printInt();
	converter->printFloat();
	converter->printDouble();

	delete(converter);
	return 0;
}