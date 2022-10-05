/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 18:00:39 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 15:39:00 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "main.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		MutantStack<T>();
		MutantStack<T>(MutantStack<T> const & src);
		~MutantStack<T>(void);

		iterator	begin(void) { return this->c.begin(); }
		iterator	end(void) { return this->c.end(); }
		const_iterator	begin(void) const { return this->c.begin(); }
		const_iterator	end(void) const { return this->c.end(); }
		reverse_iterator	rbegin(void) { return this->c.begin(); }
		reverse_iterator	rend(void) { return this->c.end(); }
		const_reverse_iterator	rbegin(void) const { return this->c.begin(); }
		const_reverse_iterator	rend(void) const { return this->c.end(); }

		MutantStack<T> &	operator=(MutantStack<T> const & rhs);
};

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "MutantStack Default constructor called" << std::endl;
	return;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const & src)
{
	std::cout << "MutantStack Copy constructor called" << std::endl;
	return (*this = src);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << "MutantStack destructor called" << std::endl;
	return;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	*this = rhs;
	return (*this);
}