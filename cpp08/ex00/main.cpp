/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:58:00 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/04 12:00:12 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int	main()
{
	std::vector<int> v;
	std::list<int> l;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	try
	{
		easyfind(v, 2);
		std::cout << "Found 2 in vector\n";

		easyfind(l, 20);
		std::cout << "Found 20 in list\n";

		easyfind(v, 42);
		std::cout << "Found 42 in vector\n";
	}
	catch(const std::exception &e)
	{
		std::cout << "Value not found\n";
	}

	return (0);
}
