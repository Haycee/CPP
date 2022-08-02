/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:10:31 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/12 19:14:25 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int	main(void)
{
	Fixed a(10);
	Fixed b(20);


	std::cout << std::endl << std::endl;

	std::cout << a << std::endl;

	++a;

	std::cout << a << std::endl;


	std::cout << std::endl << std::endl;
	
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;

	// std::cout << b << std::endl;

	// std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}