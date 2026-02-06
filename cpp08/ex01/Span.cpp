/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:51:29 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/05 01:51:55 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <stdexcept>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int size) : _maxSize(size)
{
	_data.reserve(_maxSize);
}

Span::Span(const Span &other)
{
	_maxSize = other._maxSize;
	_data = other._data;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_data = other._data;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int number)
{
	if (_data.size() >= _maxSize)
		throw std::out_of_range("Span is full");
	_data.push_back(number);
}

unsigned int	Span::shortestSpan()
{
	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers to  find a span");

	std::vector<int>	data_copy = _data;
	std::sort(data_copy.begin(), data_copy.end());

	unsigned int	diff;
	unsigned int	minDiff = UINT_MAX;

	for (size_t i = 0; i < data_copy.size() - 1; i++)
	{
		diff = std::abs(data_copy[i + 1] - data_copy[i]);
		if (diff < minDiff)
			minDiff = diff;
	}
	return (minDiff);
}

unsigned int	Span::longestSpan()
{
	if (_data.size() < 2)
		throw std::logic_error("Not enough numbers to  find a span");

	std::vector<int>::iterator	max_it = std::max_element(_data.begin(), _data.end());
	std::vector<int>::iterator	min_it = std::min_element(_data.begin(), _data.end());

	return (*max_it - *min_it);
}
