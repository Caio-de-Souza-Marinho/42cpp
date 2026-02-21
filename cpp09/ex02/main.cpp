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
#include <stdexcept>

int	main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::runtime_error("Error");

		PmergeMe	p;

		p.parseInput(argc, argv);
		p.process();
	}
	catch (const std::exception &e)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}

	return (0);
}
