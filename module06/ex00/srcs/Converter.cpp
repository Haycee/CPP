/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:10:33 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/27 17:04:11 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Converter::Converter()
{
	std::cout << "Converter Default constructor called" << std::endl;
	return;
}

Converter::Converter(std::string literal)
{
	std::cout << "Converter constructor called" << std::endl;
	if (this->Converter::parseInput(literal) == 0)
		throw ParsingException();
	this->_literal = strtod(const_cast<char*>(literal.c_str()), NULL);
}

Converter::Converter(Converter const & src) 
{
	std::cout << "Converter Copy constructor called" << std::endl;
	*this = src;
}

Converter::~Converter(void)
{
	std::cout << "Converter Destructor called" << std::endl;
	return;
}

int	Converter::isExeption(std::string literal) const
{
	std::string exeptions[5] = {"nan", "inf", "-inf", "inff", "-inff"};

	for (int i = 0; i < 5; i++)
	{
		if (literal == exeptions[i])
			return (1);
	}
	return (0);
}


int	Converter::parseInput(std::string literal) const
{
	int start = 0;
	int	dotCount = 0;

	if (isExeption(literal))
		return (1);

	if (literal[0] == '-' || literal[0] == '+')
		start++;

	for (unsigned long i = start; i < literal.length() - 1; i++)
	{
		if (!std::isdigit(literal[i]))
		{
			if (literal[i] == '.')
				dotCount++;
			else
				return (false);
		}
	}

	if (!std::isdigit(literal[literal.length() - 1]))
		if (literal[literal.length() - 1] != 'f')
			return (0);
	
	if (dotCount > 1)
		return (0);
	
	return (1);
}

void	Converter::printChar(void) const
{
	if (this->_literal > 32 && this->_literal < 127)
		std::cout << "char	: '" << static_cast<char>(this->_literal) << "'" << std::endl;
	else if ((this->_literal >= 0 && this->_literal <= 32) || this->_literal == 127)
		std::cout << "char	: Non displayable" << std::endl;
	else
		std::cout << "char	: impossible" << std::endl;
}

void	Converter::printInt(void) const
{
	if (this->_literal > INT_MIN && this->_literal < INT_MAX)
		std::cout << "int	: " << static_cast<int>(this->_literal) << std::endl;
	else
		std::cout << "int	: impossible" << std::endl;
}

void	Converter::printFloat(void) const
{
	if (this->_literal < -FLT_MAX || this->_literal > FLT_MAX)
		std::cout << "float	: inff" << std::endl;
	else if (static_cast<float>(this->_literal) == static_cast<int>(this->_literal))
		std::cout << "float	: " << static_cast<float>(this->_literal) << ".0f" << std::endl;
	else
		std::cout << "float	: " << static_cast<float>(this->_literal) << "f" << std::endl;
}

void	Converter::printDouble(void) const
{
	if (this->_literal == static_cast<int>(this->_literal))
		std::cout << "double	: " << this->_literal << ".0" << std::endl;
	else
		std::cout << "double	: " << this->_literal << std::endl;
}

double	Converter::getLiteral(void) const
{
	return(this->_literal);
}

Converter & Converter::operator=(Converter const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_literal = rhs.getLiteral();
	return (*this);
}