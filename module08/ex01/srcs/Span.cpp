/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:59:38 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 15:21:58 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Span::Span()
{
	std::cout << "Span Default constructor called" << std::endl;
	return;
}

Span::Span(unsigned int N) : _size(N)
{
	std::cout << "Span constructor called" << std::endl;
	return;
}

Span::Span(Span const & src) 
{
	std::cout << "Span Copy constructor called" << std::endl;
	*this = src;
}

Span::~Span(void)
{
	std::cout << "Span Destructor called" << std::endl;
	return;
}

void	Span::addNumber(int num)
{
	if (this->_vect.size() + 1 > this->_size)
		throw classFullException();
	this->_vect.push_back(num);
}

void	Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int>::iterator	it;

	for (it = begin; it < end; ++it)
	{
		if (this->_vect.size() + 1 > this->_size)
			throw classFullException();
		addNumber(*it);
	}
}

int	Span::shortestSpan(void)
{
	int	min;
	int	vectSize;

	if (this->_vect.size() < 2)
		throw insufficientElementsException();

	std::sort(this->_vect.begin(), this->_vect.end());

	vectSize = this->_vect.size();
	min = this->_vect[vectSize - 1] - this->_vect[vectSize - 2];

	for (int i = vectSize - 1; i > 0 ; i--)
	{
		if (this->_vect[i] - this->_vect[i - 1] < min)
			min = this->_vect[i] - this->_vect[i - 1];
	}

	return (min);
}

int	Span::longestSpan(void)
{
	int	max;
	int	min;
	
	if (this->_vect.size() < 2)
		throw insufficientElementsException();

	max = *(std::max_element(this->_vect.begin(), this->_vect.end()));
	min = *(std::min_element(this->_vect.begin(), this->_vect.end()));

	return (max - min);
}

unsigned int Span::getSize(void) const
{
	return (this->_size);
}

std::vector<int>	Span::getVector(void) const
{
	return	(this->_vect);
}

Span & Span::operator=(Span const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_size = rhs.getSize();
	this->_vect = rhs.getVector();
	return (*this);
}
