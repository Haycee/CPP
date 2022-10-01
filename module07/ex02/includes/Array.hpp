/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agirardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:37:07 by agirardi          #+#    #+#             */
/*   Updated: 2022/10/01 14:09:13 by agirardi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "main.hpp"

template <typename T>
class Array
{
	public:

		Array();
		Array(unsigned int n);
		Array(Array<T> & src);
		~Array(void);

		int	size(void) const;
		T	*getArray(void) const;

		Array<T>	& operator=(Array<T> & rhs);
		T			& operator[](int);

		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Index is out of range.");
				}
		};

	private:

		T	*_array;
		int	_size;
};

template <typename T>
Array<T>::Array()
{
	std::cout << "Array Default constructor called" << std::endl;
	this->_array = new T[0];
	this->_size = 0;
	return;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	std::cout << "Array constructor called" << std::endl;
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; i++)
	{
		this->_array[i] = 0;
	}
	return;
}

template <typename T>
Array<T>::Array(Array<T> & src) 
{
	std::cout << "Array Copy constructor called" << std::endl;
	*this = src;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << "Array Destructor called" << std::endl;
	delete[] this->_array;
	return;
}

template <typename T>
int	Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
T	*Array<T>::getArray(void) const
{
	return (this->_array);
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_size = rhs.size();
	this->_array = new T[this->_size];
	T	*buffer = rhs.getArray();
	for (int i = 0; i < this->_size; i++)
	{
		this->_array[i] = buffer[i];
	}
	return (*this);
}

template <typename T>
T	& Array<T>::operator[](int index)
{
	if ( index < 0 || index >= this->_size)
		throw OutOfRangeException();
	return this->_array[index];
}