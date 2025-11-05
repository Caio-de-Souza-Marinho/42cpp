/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:02:00 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/04 21:39:20 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl		h;
	std::string	level;

	std::cout << "Choose a level: DEBUG, INFO, WARNING, ERROR" << std::endl;
	std::cout << "- ";
	std::cin >> level;

	h.complain(level);
	return (0);
}
