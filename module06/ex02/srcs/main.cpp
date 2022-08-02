/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 16:06:58 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 00:15:33 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main(void)
{
	Base	*pRandClass;

	pRandClass = generate();
	identify(pRandClass);

	Base	&rRandClass = *pRandClass;
	identify(rRandClass);

	delete pRandClass;
	return (0);
}

Base	*generate(void)
{
	int	classNum;

	srand(time(NULL));
	classNum = rand() % 3;

	switch (classNum)
	{
		case 0:
			return(static_cast<Base*>(new A()));
		case 1:
			return(static_cast<Base*>(new B()));
		case 2:
			return(static_cast<Base*>(new C()));
		default:
			return (NULL);
	}
}

void	identify(Base* p)
{
	std::string	classes = "ABC";
	void		*pointers[3];

	pointers[0] = static_cast<void*>((dynamic_cast<A*>(p)));
	pointers[1] = static_cast<void*>((dynamic_cast<B*>(p)));
	pointers[2] = static_cast<void*>((dynamic_cast<C*>(p)));
	
	for (int i = 0; i < 3; i++)
	{
		if (pointers[i] != NULL)
			std::cout << "Pointer:	The actual type of the object pointed to by p is: " << classes[i] << std::endl;
	}
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "Reference:	The actual type of the object pointed to by p is: A" << std::endl;
	}
	catch (std::bad_cast &bc) {}

	try {
		B &b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "Reference:	The actual type of the object pointed to by p is: B" << std::endl;
	}
	catch (std::bad_cast &bc) {}

	try {
		C &c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "Reference:	The actual type of the object pointed to by p is: C" << std::endl;
	}
	catch (std::bad_cast &bc) {}
}