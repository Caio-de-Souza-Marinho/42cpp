/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:15:49 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/20 21:44:03 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [argument]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
