/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:17:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/09 01:13:54 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void		printPhoneBookHeader();
std::string	verifyText(std::string text);

PhoneBook::PhoneBook() : _index(0) {}

void	PhoneBook::addContact()
{
	if (_index >= 8)
		_index %= 8;
	_contactList[_index].setContact();
	_index++;
}

void	PhoneBook::searchContact()
{
	if (!_contactList[0].getFirstName().empty())
	{
		std::cout << "\033[2J\033[H";
		printPhoneBookHeader();
		for (int i = 0; i < 8; i++)
		{
			if (!_contactList[i].getFirstName().empty())
				printContactSummary(_contactList[i], i);
		}
		std::string	input;
		while (true)
		{
			std::cout << std::endl << "Type the contact index: ";
			if (!getline(std::cin, input))
				return;
			std::istringstream iss(input);
			int	index;
			if (!(iss >> index) || index < 0 || index >= 8)
			{
				std::cout << "Invalid index. Try again." << std::endl;
				continue;
			}
			if (_contactList[index].getFirstName().empty())
			{
				std::cout << "Contact don't exist, try again" << std::endl;
				continue;
			}
			_contactList[index].displayFullContact();
			break;
		}
	}
	else
	{
		std::cout << "Add at least one contact to the phonebook before searching." << std::endl;
		return;
	}
}

void	printPhoneBookHeader()
{
	const int		width = 10;
	const std::string	separator = "|";
	const int		totalWidth = (width * 4) + 5;
	const std::string	topLine(totalWidth, '_');
	const std::string	botLine(totalWidth, '-');

	std::cout << topLine << std::endl;

	std::cout << separator 
	<< std::right << std::setw(width) << "Index" << separator 
	<< std::right << std::setw(width) << "First Name" << separator
	<< std::right << std::setw(width) << "Last Name" << separator
	<< std::right << std::setw(width) << "Nickname" << separator
	<< std::endl;

	std::cout << botLine << std::endl;
}

void	PhoneBook::printContactSummary(const Contact& contact, int i)
{
	const int		width = 10;
	const std::string	separator = "|";
	const int		totalWidth = (width * 4) + 5;
	const std::string	botLine(totalWidth, '-');

	std::cout << separator 
	<< std::right << std::setw(width) << i << separator 
	<< std::right << std::setw(width) << verifyText(contact.getFirstName()) << separator 
	<< std::right << std::setw(width) << verifyText(contact.getLastName()) << separator 
	<< std::right << std::setw(width) << verifyText(contact.getNickname()) << separator 
	<< std::endl;

	std::cout << botLine << std::endl;
}

std::string	verifyText(std::string text)
{
	std::string tmpText = text;

	if (tmpText.length() > 10)
	{
		tmpText = text.substr(0, 10);
		tmpText[9] = '.';
		return (tmpText);
	}
	return (tmpText);
}
