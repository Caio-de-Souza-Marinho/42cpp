/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:25:35 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/20 13:49:06 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

class	PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	sortVector();
		void	mergeInsertSortVector(std::vector<int> &vector);
		void	insertPendingVector(std::vector<int> &mainChain, std::vector<int> &pending);
		void	binaryInsertVector(std::vector<int> &vector, int value);

		void	sorteDeque();
		void	mergeInsertSortDeque(std::deque<int> &deque);
		void	insertPendingDeque(std::deque<int> &mainChain, std::deque<int> &pending);
		void	binaryInsertDeque(std::deque<int> &deque, int value);

		bool	isValidNumber(const std::string &token) const;
		long	convertToLong(const std::string &token) const;
		bool	isDuplicate(int value) const;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	parseInput(int argc, char **argv);
		void	process();
};

#endif
