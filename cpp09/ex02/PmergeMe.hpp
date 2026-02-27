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

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class	PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	sortVector();
		void	mergeInsertSortVector(std::vector<int> &vector);
		void	binaryInsertVector(std::vector<int> &vector, int value, size_t upperBound);

		void	sortDeque();
		void	mergeInsertSortDeque(std::deque<int> &deque);
		void	binaryInsertDeque(std::deque<int> &deque, int value, size_t upperBound);

		// parse input helpers
		bool	isValidNumber(const std::string &token) const;
		long	convertToLong(const std::string &token) const;
		bool	isDuplicate(int value) const;

		// process helpers
		void	printSequence(const std::string &label) const;
		void	printTimeVector(clock_t startVector, clock_t endVector);
		void	printTimeDeque(clock_t startDeque, clock_t endDeque);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	parseInput(int argc, char **argv);
		void	process();
};

#endif
