/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:15:52 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/27 11:17:37 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int	main()
{
	// Seed the random number generator using the current time
	// This must run once per program execution
	srand(static_cast<unsigned int>(time(0)));

	std::cout << "TEST 1: dynamic_cast with pointer\n";
	Base*	p1 = generate();
	identify(p1);
	delete p1;

	std::cout << "TEST 2: dynamic_cast with references\n";
	Base*	p2 = generate();
	if (p2)
	{
		identify(*p2);
		delete p2;
	}

	return (0);
}
