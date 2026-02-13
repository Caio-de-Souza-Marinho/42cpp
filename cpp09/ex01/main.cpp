/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 07:44:08 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/13 07:44:31 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error\n";
		return (1);
	}

	RPN	rpn;
	rpn.evaluate(argv[1]);

	return (0);
}

// Test main
/*
int	main()
{
	RPN	rpn;

	std::cout << "Test 1:\n";
	rpn.evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +");

	std::cout << "\nTest 2:\n";
	rpn.evaluate("7 7 * 7 -");

	std::cout << "\nTest 3:\n";
	rpn.evaluate("1 2 * 2 / 2 * 2 4 - +");

	std::cout << "\nTest 4 (simple add):\n";
	rpn.evaluate("3 4 +");

	std::cout << "\nTest 5 (division):\n";
	rpn.evaluate("9 3 /");

	std::cout << "\nTest 6 (invalid operator):\n";
	rpn.evaluate("5 2 ^");

	std::cout << "\nTest 7 (not enough operands):\n";
	rpn.evaluate("+");

	std::cout << "\nTest 8 (too many operands):\n";
	rpn.evaluate("1 2 3 +");

	std::cout << "\nTest 9 (division by zero):\n";
	rpn.evaluate("4 0 /");

	return (0);
}
*/
