/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 15:39:00 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

class Span
{
	public:

		Span(unsigned int N);
		Span(Span const & src);
		~Span(void);

		void	addNumber(int num);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);

		unsigned int		getSize(void) const;
		std::vector<int>	getVector(void) const;

		class classFullException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Class full.");
				}
		};

		class insufficientElementsException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("There are not enough elements to complete this task.");
				}
		};

		Span &	operator=(Span const & rhs);

	private:

		Span();

		std::vector<int>	_vect;
		unsigned int		_size;
};
