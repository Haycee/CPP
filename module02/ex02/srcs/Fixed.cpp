/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:12:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/09/05 03:43:43 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Fixed::Fixed(void) : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const num) : _fixed_point_value(0)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = num << this->_fract_bits_number;
}

Fixed::Fixed(float const num) : _fixed_point_value(0)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(num * (1 << this->_fract_bits_number));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point_value / (float)(1 << this->_fract_bits_number));
}

int	Fixed::toInt(void) const
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

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	Fixed res;

	res = this->toFloat() + rhs.toFloat();
	return (res);
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	Fixed res;

	res = this->toFloat() - rhs.toFloat();
	return (res);
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	Fixed res;

	res = this->toFloat() * rhs.toFloat();
	return (res);
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	Fixed res;

	res = this->toFloat() / rhs.toFloat();
	return (res);
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
