/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:25:08 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/18 16:25:22 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vector = other._vector;
		_deque = other._deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	for (int i = 1; i < argc; i++)
	{
		std::string	token = argv[i];

		if (!isValidNumber(token))
			throw std::runtime_error("Error");

		long	value = convertToLong(token);

		if (isDuplicate(static_cast<int>(value)))
			throw std::runtime_error("Error");

		_vector.push_back(static_cast<int>(value));
		_deque.push_back(static_cast<int>(value));
	}
}

bool	PmergeMe::isValidNumber(const std::string &token) const
{
	if (token.empty())
		return (false);

	for (size_t i = 0; i < token.length(); i++)
	{
		if (!std::isdigit(token[i]))
			return (false);
	}
	return (true);
}

long	PmergeMe::convertToLong(const std::string &token) const
{
	std::stringstream	ss(token);
	long			value;

	ss >> value;

	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error");

	if (value < 0 || value > INT_MAX)
		throw std::runtime_error("Error");

	return (value);
}

bool	PmergeMe::isDuplicate(int value) const
{
	for (size_t i = 0; i < _vector.size(); i++)
	{
		if (_vector[i] == value)
			return (true);
	}
	return (false);
}
