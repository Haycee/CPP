/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:13:12 by agirardi          #+#    #+#             */
/*   Updated: 2022/07/11 18:14:18 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Fixed
{
	public:

		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed &	operator=(Fixed const & rhs);

	private:

		int					_fixed_point_value;
		int const static	_fract_bits_number = 8;
};