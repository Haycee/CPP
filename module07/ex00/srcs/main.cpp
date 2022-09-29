/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/29 13:47:04 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(void)
{
	int	a = 2;
	int	b = 3;

	std::cout << "Before Swap : a = " << a << ", b = " << b << std::endl;
	::swap<int>( a, b );
	std::cout << "After Swap  : a = " << a << ", b = " << b << std::endl << std::endl;
	std::cout << "min( a, b ) = " << ::min<int>( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max<int>( a, b ) << std::endl;

	std::cout << std::endl << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "Before Swap : c = " << c << ", d = " << d << std::endl;
	::swap<std::string>(c, d);
	std::cout << "After Swap  : c = " << c << ", d = " << d << std::endl << std::endl;
	std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;

	return (0);
}
