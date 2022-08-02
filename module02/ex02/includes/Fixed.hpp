/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:13:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/12 19:48:29 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Fixed
{
	public:

		Fixed(void);
		Fixed(int const num);
		Fixed(float const num);
		Fixed(Fixed const & src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &			min(Fixed & n1, Fixed & n2);
		static const Fixed &	min(Fixed const & n1, Fixed const & n2);
		static Fixed &			max(Fixed & n1, Fixed & n2);
		static const Fixed &	max(Fixed const & n1, Fixed const & n2);

		Fixed &	operator=(Fixed const & rhs);

		bool	operator>(Fixed const & rhs) const;
		bool	operator<(Fixed const & rhs) const;
		bool	operator>=(Fixed const & rhs) const;
		bool	operator<=(Fixed const & rhs) const;
		bool	operator==(Fixed const & rhs) const;
		bool	operator!=(Fixed const & rhs) const;

		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);

		Fixed &	operator++();
		Fixed	operator++(int);
		Fixed &	operator--();
		Fixed	operator--(int);

	private:

		int					_fixed_point_value;
		int const static	_fract_bits_number = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);