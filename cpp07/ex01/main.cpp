/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 10:47:58 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/28 16:02:57 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

// Test functions

template <typename T>
void	print(const T& x)
{
	std::cout << x << std::endl;
}

template <typename T>
void	printSquared(const T& x)
{
	std::cout << (x * x) << std::endl;
}

void	printLength(const std::string& s)
{
	std::cout << s.length() << std::endl;
}

int	main()
{
	std::cout << "========== TEST 1: int array / print ==========" << std::endl;
	int intArr[] = {1, 2, 3, 4};
	::iter(intArr, 4, print<int>);

	std::cout << "\n========== TEST 2: int array / squared ==========" << std::endl;
	::iter(intArr, 4, printSquared<int>);

	std::cout << "\n========== TEST 3: const int array ==========" << std::endl;
	const int constIntArr[] = {5, 6, 7};
	::iter(constIntArr, 3, print<int>);

	std::cout << "\n========== TEST 4: string array / print ==========" << std::endl;
	std::string strArr[] = {"hello", "42", "world"};
	::iter(strArr, 3, print<std::string>);

	std::cout << "\n========== TEST 5: string array / length ==========" << std::endl;
	::iter(strArr, 3, printLength);

	std::cout << "\n========== TEST 6: size = 0 (edge case) ==========" << std::endl;
	::iter(intArr, 0, print<int>);

	std::cout << "\n========== ALL TESTS DONE ==========" << std::endl;
	return 0;
}
