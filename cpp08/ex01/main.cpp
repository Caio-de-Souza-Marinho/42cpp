/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 01:49:55 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/05 01:51:15 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main()
{
	srand(static_cast<unsigned int>(time(0)));

	const int	size = 10;
	const int	min = 1;
	const int	max = 1000;

	Span	sp(size);
	std::vector<int>	numbers;

	for (int i = 0; i < size; i++)
	{
		int	value = min + (std::rand() % (max - min + 1));
		numbers.push_back(value);
	}

	std::cout << "\n==================== Span content ====================\n";
	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << "\n==================== ------------ ====================\n";

	sp.addNumbers(numbers.begin(), numbers.end());

	std::cout << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	return (0);
}
