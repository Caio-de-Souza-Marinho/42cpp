/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 22:18:29 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/25 23:16:50 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	std::cout << "TEST 1: stack allocation\n";

	Data	data1;
	data1.value = 42;
	Data*	ptr1 = &data1;

	uintptr_t	raw1 = Serializer::serialize(ptr1);
	Data*		back1 = Serializer::deserialize(raw1);

	if (back1 == ptr1)
		std::cout << "OK\n";
	else
		std::cout << "FAIL\n";

	std::cout << "TEST 2: heap allocation\n";

	Data*	ptr2 = new Data;
	ptr2->value = 24;

	uintptr_t	raw2 = Serializer::serialize(ptr2);
	Data*		back2 = Serializer::deserialize(raw2);

	if (back2 == ptr2)
		std::cout << "OK\n";
	else
		std::cout << "FAIL\n";

	std::cout << "TEST 3: distinct addresses\n";

	if (raw1 != raw2)
		std::cout << "OK\n";
	else
		std::cout << "FAIL\n";

	std::cout << "TEST 4: data integrity\n";
	
	if (back1->value == 42 && back2->value == 24)
		std::cout << "OK\n";
	else
		std::cout << "FAIL\n";

	delete ptr2;

	return (0);
}
