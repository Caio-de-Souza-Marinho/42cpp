/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:21:08 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/28 10:43:45 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "functions.hpp"

int	main()
{
	std::cout << "\n========== TEST 1: SWAP (int) ==========" << std::endl;
	int a = 2;
	int b = 4;
	std::cout << "Before: " << a << " | " << b << std::endl;
	::swap(a, b);
	std::cout << "After : " << a << " | " << b << std::endl;

	std::cout << "\n========== TEST 2: SWAP (string) ==========" << std::endl;
	std::string s1 = "hello";
	std::string s2 = "world";
	std::cout << "before: " << s1 << " | " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "after : " << s1 << " | " << s2 << std::endl;

	std::cout << "\n========== test 3: swap (same values) ==========" << std::endl;
	int x = 42;
	int y = 42;
	std::cout << "before: " << x << " | " << y << std::endl;
	::swap(x, y);
	std::cout << "after : " << x << " | " << y << std::endl;

	std::cout << "\n========== test 4: min (int) ==========" << std::endl;
	int c = 5;
	int d = 6;
	std::cout << "min(5, 6) = " << ::min(c, d) << std::endl;
	std::cout << "min(6, 5) = " << ::min(d, c) << std::endl;

	std::cout << "\n========== test 5: min (equal values) ==========" << std::endl;
	int e = 10;
	int f = 10;
	std::cout << "addresses: e=" << &e << " f=" << &f << std::endl;
	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "returned address = " << &::min(e, f) << std::endl;

	std::cout << "\n========== test 6: max (int) ==========" << std::endl;
	int g = 7;
	int h = 3;
	std::cout << "max(7, 3) = " << ::max(g, h) << std::endl;
	std::cout << "max(3, 7) = " << ::max(h, g) << std::endl;

	std::cout << "\n========== test 7: max (equal values) ==========" << std::endl;
	int i = 99;
	int j = 99;
	std::cout << "addresses: i=" << &i << " j=" << &j << std::endl;
	std::cout << "max(i, j) = " << ::max(i, j) << std::endl;
	std::cout << "returned address = " << &::max(i, j) << std::endl;

	std::cout << "\n========== test 8: const values ==========" << std::endl;
	const int k = 1;
	const int l = 2;
	std::cout << "min(const, const) = " << ::min(k, l) << std::endl;
	std::cout << "max(const, const) = " << ::max(k, l) << std::endl;

	std::cout << "\n========== test 9: string min / max ==========" << std::endl;
	std::string s3 = "apple";
	std::string s4 = "banana";
	std::cout << "min(\"apple\", \"banana\") = " << ::min(s3, s4) << std::endl;
	std::cout << "max(\"apple\", \"banana\") = " << ::max(s3, s4) << std::endl;


	std::cout << "\n========== all tests done ==========" << std::endl;
	return 0;
}
