/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:53:14 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/08 01:08:53 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

int	main(void)
{
	std::string	command;
	Contact		contact1;

	while (true)
	{
		getline(std::cin, command);
		if (command == "ADD")
		{
			std::cout << "ok" << std::endl;
			contact1.setContact();
		}
		else if (command == "SEARCH")
			std::cout << "ok" << std::endl;
		else if (command == "EXIT")
			break;
		else
			std::cout << "WRONG" << std::endl; 
	}
	return (0);
}
