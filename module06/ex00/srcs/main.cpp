/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/27 17:05:40 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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

	std::cout << std::endl;

	converter->printChar();
	converter->printInt();
	converter->printFloat();
	converter->printDouble();

	std::cout << std::endl;

	delete(converter);
	return 0;
}