/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:12:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/03 01:51:18 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point_value = 0;
	return;
}

Fixed::Fixed(int const num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = num << this->_fract_bits_number;
}

Fixed::Fixed(float const num)
{
	std::cout << "Float constructor called" << std::endl;
	// this->_fixed_point_value = roundf(num * std::pow(2, _fract_bits_number)); ?
	this->_fixed_point_value = roundf(num * (1 << this->_fract_bits_number));
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point_value / (float)(1 << this->_fract_bits_number));
}

int		Fixed::toInt(void) const
{
	return ((int)this->_fixed_point_value >> this->_fract_bits_number);
}

Fixed &	Fixed::min(Fixed & n1, Fixed & n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

const Fixed &	Fixed::min(Fixed const & n1, Fixed const & n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed &	Fixed::max(Fixed & n1, Fixed & n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed &	Fixed::max(Fixed const & n1, Fixed const & n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_fixed_point_value = rhs.getRawBits();
	return (*this);
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	return (o << rhs.toFloat());
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	if (this->_fixed_point_value > rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	if (this->_fixed_point_value < rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	if (this->_fixed_point_value >= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	if (this->_fixed_point_value <= rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	if (this->_fixed_point_value == rhs.getRawBits())
		return true;
	return false;
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	if (this->_fixed_point_value != rhs.getRawBits())
		return true;
	return false;
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	return Fixed(this->toInt() + rhs.toInt());
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	return Fixed(this->toInt() - rhs.toInt());
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed &	Fixed::operator++()
{
	this->_fixed_point_value++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++*this;
	return temp;
}

Fixed &	Fixed::operator--()
{
	this->_fixed_point_value--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--*this;
	return temp;
}

