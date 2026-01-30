/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:08:00 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/30 02:38:06 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class	Array
{
	private:
		unsigned int	_size;
		T*		_data;
		
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array();

		T		&operator[](unsigned int index);
		const T		&operator[](unsigned int index) const;

		unsigned int	size() const;
};

template <typename T>
Array<T>::Array()
{
	_size = 0;
	_data = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_size = n;
	_data = new T[n];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	_size = other._size;
	_data = new T[_size];

	for (unsigned int i = 0; i < _size; i++)
		_data[i] = other._data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_data[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

#endif
