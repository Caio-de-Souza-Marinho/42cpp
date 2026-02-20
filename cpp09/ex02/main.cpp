/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:38:12 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/20 11:38:55 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error\n";
		return (1);
	}

	PmergeMe	p;

	p.parseInput(argc, argv);
	p.process();

	return (0);
}
