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

// --------- Input parsing -----------------------------------------------------------------

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

// --------- Jabobsthal insertion order -----------------------------------------------------------------

static std::vector<size_t>	buildInsertionOrder(size_t size)
{
	std::vector<size_t>	order;
	if (size == 0)
		return (order);

	order.push_back(0);
	if (size == 1)
		return (order);

	std::vector<size_t>	jacob;
	jacob.push_back(1);
	jacob.push_back(3);

	while (jacob.back() < size)
		jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);

	size_t	prev = 1;
	for (size_t i = 1; i < jacob.size(); i++)
	{
		size_t	curr = jacob[i];
		if (curr > size)
			curr = size;
		if (curr <= prev)
			continue ;

		for (size_t j = curr; j > prev; j--)
			order.push_back(j - 1);
		prev = curr;
		if (prev >= size)
			break ;
	}

	return (order);
}


// --------- Sort Vector -----------------------------------------------------------------

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
	for (size_t i = 0; i + 1 < vector.size(); i += 2)
	{
		int	first = vector[i];
		int	second = vector[i + 1];

		if (first > second)
			std::swap(first, second);

		pending.push_back(first);
		mainChain.push_back(second);
	}

	bool	hasStraggler = (vector.size() % 2 != 0);
	int	straggler = hasStraggler ? vector.back() : 0;

	std::vector<int>	origMainChain = mainChain;

	// Step 2: Recursively sort main chain
	mergeInsertSortVector(mainChain);

	std::vector<int>	origMainChainCopy = origMainChain;
	std::vector<int>	pendingAligned;

	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = 0; j < origMainChain.size(); j++)
		{
			if (origMainChainCopy[j] == mainChain[i])
			{
				pendingAligned.push_back(pending[j]);
				origMainChainCopy[j] = -1;
				break;
			}
		}
	}
	pending = pendingAligned;

	if (hasStraggler)
		pending.push_back(straggler);

	std::vector<size_t>	order = buildInsertionOrder(pending.size());

	size_t	inserted = 0;
	for (size_t j = 0; j < order.size(); j++)
	{
		size_t	idx = order[j];
		size_t	upperBound;

		if (hasStraggler && idx == pending.size() - 1)
			upperBound = mainChain.size();
		else
			upperBound = idx + inserted + 1;

		if (upperBound > mainChain.size())
			upperBound = mainChain.size();

		binaryInsertVector(mainChain, pending[idx], upperBound);
		inserted++;
	}

	vector = mainChain;
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

// --------- Sort Deque -----------------------------------------------------------------

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
	for (size_t i = 0; i + 1 < deque.size(); i += 2)
	{
		int	first = deque[i];
		int	second = deque[i + 1];

		if (first > second)
			std::swap(first, second);

		pending.push_back(first);
		mainChain.push_back(second);
	}

	bool	hasStraggler = (deque.size() % 2 != 0);
	int	straggler = hasStraggler ? deque.back() : 0;

	std::deque<int>	origMainChain = mainChain;

	// Step 2: Recursively sort main chain
	mergeInsertSortDeque(mainChain);

	std::deque<int>	origMainChainCopy = origMainChain;
	std::deque<int>	pendingAligned;

	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = 0; j < origMainChain.size(); j++)
		{
			if (origMainChainCopy[j] == mainChain[i])
			{
				pendingAligned.push_back(pending[j]);
				origMainChainCopy[j] = -1;
				break;
			}
		}
	}
	pending = pendingAligned;

	if (hasStraggler)
		pending.push_back(straggler);

	std::vector<size_t>	order = buildInsertionOrder(pending.size());

	size_t	inserted = 0;
	for (size_t j = 0; j < order.size(); j++)
	{
		size_t	idx = order[j];
		size_t	upperBound;

		if (hasStraggler && idx == pending.size() - 1)
			upperBound = mainChain.size();
		else
			upperBound = idx + inserted + 1;

		if (upperBound > mainChain.size())
			upperBound = mainChain.size();

		binaryInsertDeque(mainChain, pending[idx], upperBound);
		inserted++;
	}

	deque = mainChain;
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

// --------- Output --------------------------------------------------------------------------

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

	duration = (double)(endDeque - startDeque) / CLOCKS_PER_SEC;
	duration *= 1000000;

	std::cout << "Time to process a range of   " 
		<< _deque.size()
		<< " elements with std::deque<int> : "
		<< duration
		<< " us"
		<< std::endl;
}
