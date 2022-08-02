/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:10:32 by agirardi          #+#    #+#             */
/*   Updated: 2022/08/02 03:26:02 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Converter
{
	public:

		Converter();
		Converter(std::string literal);
		Converter(Converter const & src);
		virtual ~Converter(void);

		void	printChar(void) const;
		void	printInt(void) const;
		void	printFloat(void) const;
		void	printDouble(void) const;

		double	getLiteral(void) const;

		class ParsingException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("The literal can only be of the following types: char, int, float, or double.");
				}
		};

		Converter &	operator=(Converter const & rhs);

	private:

		double	_literal;

		int	parseInput(std::string literal) const;
};

std::ostream &	operator<<(std::ostream & o, Converter const & rhs);

