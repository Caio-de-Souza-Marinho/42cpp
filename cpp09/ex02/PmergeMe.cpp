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
#include <iomanip>
#include <ios>
#include <iostream>
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

void	PmergeMe::process()
{
	printSequence("Before");

	clock_t	startVector = clock();
	sortVector();
	clock_t	endVector = clock();

	clock_t	startDeque = clock();
	sortDeque();
	clock_t	endDeque = clock();

	printSequence("After");

	printTimeVector(startVector, endVector);
	printTimeDeque(startDeque, endDeque);
}

void	PmergeMe::printSequence(const std::string &label) const
{
	std::cout << label << ":\t";

	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::sortVector()
{
	mergeInsertSortVector(_vector);
}

void	PmergeMe::mergeInsertSortVector(std::vector<int> &vector)
{
	if (vector.size() <= 1)
		return ;

	std::vector<int>	mainChain;
	std::vector<int>	pending;

	// Step 1: Create pairs
	size_t	i = 0;
	while (i + 1 < vector.size())
	{
		int	first = vector[i];
		int	second = vector[i + 1];

		if (first > second)
			std::swap(first, second);

		pending.push_back(first);
		mainChain.push_back(second);

		i += 2;
	}

	// Odd element goes to pending
	if (vector.size() % 2 != 0)
		pending.push_back(vector.back());

	// Step 2: Recursively sort main chain
	mergeInsertSortVector(mainChain);

	// Step 3: Generate Jacobsthal insertion order
	std::vector<size_t>	order = generateJacobsthalOrderVector(pending.size());

	// Step 4: Insert pending elements in Jacobsthal order
	for (size_t j = 0; j < order.size(); j++)
	{
		size_t	idx = order[j];

		// Restrict binary search range
		size_t	upperBound = idx + j;

		if (upperBound > mainChain.size())
			upperBound = mainChain.size();

		binaryInsertVector(mainChain, pending[idx], upperBound);
	}

	vector = mainChain;
}

std::vector<size_t>	PmergeMe::generateJacobsthalOrderVector(size_t size)
{
	std::vector<size_t> order;

	if (size == 0)
		return order;

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	while (jacob.back() < size)
		jacob.push_back(jacob[jacob.size() - 1] +
		  2 * jacob[jacob.size() - 2]);

	size_t prev = 1;

	for (size_t i = 2; i < jacob.size(); i++)
	{
		size_t curr = jacob[i];
		if (curr > size)
			curr = size;

		for (size_t j = curr; j > prev; j--)
			order.push_back(j - 1);

		prev = curr;
	}

	return order;
}

void	PmergeMe::binaryInsertVector(std::vector<int> &vector, int value, size_t upperBound)
{
	size_t	left = 0;
	size_t	right = upperBound;

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;

		if (vector[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	vector.insert(vector.begin() + left, value);
}

void	PmergeMe::sortDeque()
{
	mergeInsertSortDeque(_deque);
}

void	PmergeMe::mergeInsertSortDeque(std::deque<int> &deque)
{
	if (deque.size() <= 1)
		return ;

	std::deque<int>	mainChain;
	std::deque<int>	pending;

	// Step 1: Create pairs
	size_t	i = 0;
	while (i + 1 < deque.size())
	{
		int	first = deque[i];
		int	second = deque[i + 1];

		if (first > second)
			std::swap(first, second);

		pending.push_back(first);
		mainChain.push_back(second);

		i += 2;
	}

	// Odd element
	if (deque.size() % 2 != 0)
		pending.push_back(deque.back());

	// Step 2: Recursively sort main chain
	mergeInsertSortDeque(mainChain);

	// Step 3: Generate Jacobsthal insertion order
	std::deque<size_t>	order = generateJacobsthalOrderDeque(pending.size());

	// Step 4: Insert pending elements in Jacobsthal order
	for (size_t j = 0; j < order.size(); j++)
	{
		size_t	idx = order[j];

		// Restrict binary search range
		size_t	upperBound = idx + j;

		if (upperBound > mainChain.size())
			upperBound = mainChain.size();

		binaryInsertDeque(mainChain, pending[idx], upperBound);
	}

	deque = mainChain;
}

std::deque<size_t>	PmergeMe::generateJacobsthalOrderDeque(size_t size)
{
	std::deque<size_t>	order;
	if (size == 0)
		return (order);

	std::deque<size_t>	jacob;
	jacob.push_back(0);
	jacob.push_back(1);

	while (jacob.back() < size)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	size_t	inserted = 0;

	for (size_t i = 1; i < jacob.size(); i++)
	{
		size_t	limit = jacob[i];
		if (limit > size)
			limit = size;

		for (size_t j = limit ; j > inserted; j--)
			order.push_back(j - 1);

		inserted = limit;
	}

	return (order);
}

void	PmergeMe::binaryInsertDeque(std::deque<int> &deque, int value, size_t upperBound)
{
	size_t	left = 0;
	size_t	right = upperBound;

	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;

		if (deque[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	deque.insert(deque.begin() + left, value);
}

void	PmergeMe::printTimeVector(clock_t startVector, clock_t endVector)
{
	double	duration;

	duration = (double)(endVector - startVector) / CLOCKS_PER_SEC;
	duration *= 1000000;

	std::cout << "Time to process a range of   " 
		<< _vector.size()
		<< " elements with std::vector<int> : "
		<< duration
		<< " us"
		<< std::endl;
}

void	PmergeMe::printTimeDeque(clock_t startDeque, clock_t endDeque)
{
	double	duration;

	duration = (double)(endDeque- startDeque) / CLOCKS_PER_SEC;
	duration *= 1000000;

	std::cout << "Time to process a range of   " 
		<< _deque.size()
		<< " elements with std::deque<int> : "
		<< duration
		<< " us"
		<< std::endl;
}
