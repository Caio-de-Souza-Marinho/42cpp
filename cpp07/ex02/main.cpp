/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:07:15 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/30 02:51:26 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n========== TEST 1: empty array ==========\n";

	Array<int>	empty;
	std::cout << "size: " << empty.size() << std::endl;

	try
	{
		std::cout << empty[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n========== TEST 2: int array ==========\n";

	Array<int>	a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== TEST 3: int array ==========\n";

	Array<int>	b(a);
	b[0] = 999;

	std::cout << "original: a[0]: " << a[0] << std::endl;
	std::cout << "copy: b[0]: " << b[0] << std::endl;

	std::cout << "\n========== TEST 4: assignment operator ==========\n";

	Array<int>	c;
	c = a;
	c[1] = 777;

	std::cout << "a[1]: " << a[1] << std::endl;
	std::cout << "c[1]: " << c[1] << std::endl;

	std::cout << "\n========== TEST 5: const array ==========\n";

	const Array<int>	d(a);

	for (unsigned int i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== TEST 6: string array ==========\n";

	Array<std::string>	s(3);
	s[0] = "hello";
	s[1] = "beautiful";
	s[2] = "world!";

	for (unsigned int i = 0; i < s.size(); i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;

	std::cout << "\n========== TEST 7: out of bounds ==========\n";

	try
	{
		std::cout << s[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n========== ALL TESTS DONE ==========\n";

	return (0);
}
