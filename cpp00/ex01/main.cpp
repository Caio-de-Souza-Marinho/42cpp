/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 23:53:14 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/09 01:01:41 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void	printWelcome(void);
void	printAvailableCommands();

int	main(void)
{
	std::cout << "\033[2J\033[H";
	printWelcome();

	std::string	command;
	PhoneBook	phoneBook;

	while (true)
	{
		std::cout << std::endl << "> ";
		getline(std::cin, command);
		if (command == "ADD")
		{
			phoneBook.addContact();
			printAvailableCommands();
		}
		else if (command == "SEARCH")
		{
			phoneBook.searchContact();
			printAvailableCommands();
		}
		else if (command == "EXIT")
			break;
		else
		{
			std::cout << "Command not found, try again." << std::endl; 
			printAvailableCommands();
		}
	}
	return (0);
}

void	printWelcome(void)
{
	std::string	line = "========================";
	std::cout << line << std::endl;
	std::cout << "Welcome to the Phonebook" << std::endl;
	std::cout << line << std::endl;
	std::cout << "This phonebook can store up to 8 contacts." << std::endl;
	printAvailableCommands();
}

void	printAvailableCommands()
{
	std::cout << std::endl << "Available commands:" << std::endl;
	std::cout << "ADD\t- Add a new contact" << std::endl;
	std::cout << "SEARCH\t- Search and display contacts" << std::endl;
	std::cout << "EXIT\t- Quit the program" << std::endl;
}
