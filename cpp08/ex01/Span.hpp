/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:46:34 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/05 01:50:55 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class	Span
{
	private:
		std::vector<int>	_data;
		unsigned int		_maxSize;

	public:
		Span();
		Span(unsigned int size);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void		addNumber(int number);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		
		template <typename T>
		void	addNumbers(T begin, T end)
		{
			unsigned int	distance = std::distance(begin, end);

			if (_data.size() + distance > _maxSize)
				throw std::out_of_range("Span overflow");

			_data.insert(_data.end(), begin, end);
		}
};

#endif
