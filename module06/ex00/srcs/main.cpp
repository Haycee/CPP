/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/02 18:57:48 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/*
	Gérer +a || -a || 4fffffff ?
*/

int main(int argc, char *argv[])
{
	std::string	literal;
	Converter	*converter;

	if (argc != 2)
	{
		std::cout << "Usage: ./convert literal" << std::endl;
		return (0);
	}

	literal = argv[1];

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