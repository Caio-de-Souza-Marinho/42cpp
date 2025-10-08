/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 00:59:54 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/08 01:08:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

void	Contact::setFirstName()
{
	std::string	input;

	do
	{
		std::cout << "Enter first name: ";
		getline(std::cin, input);
		if (input.empty())
			std::cout << "First name can't be blank" << std::endl;
		else
		{
			_firstName = input;
			break;
		}
	}
	while (true);
}

void	Contact::setLastName()
{
	std::string	input;

	do
	{
		std::cout << "Enter last name: ";
		getline(std::cin, input);
		if (input.empty())
			std::cout << "Last name can't be blank" << std::endl;
		else
		{
			_lastName = input;
			break;
		}
	}
	while (true);
}

void	Contact::setNickname()
{
	std::string	input;

	do
	{
		std::cout << "Enter nickname: ";
		getline(std::cin, input);
		if (input.empty())
			std::cout << "Nickname can't be blank" << std::endl;
		else
		{
			_nickname = input;
			break;
		}
	}
	while (true);
}

void	Contact::setPhoneNumber()
{
	std::string	input;

	do
	{
		std::cout << "Enter phone number: ";
		getline(std::cin, input);
		if (input.empty())
			std::cout << "Phone number can't be blank" << std::endl;
		else
		{
			_phoneNumber = input;
			break;
		}
	}
	while (true);
}

void	Contact::setDarkestSecret()
{
	std::string	input;

	do
	{
		std::cout << "Enter darkest secret: ";
		getline(std::cin, input);
		if (input.empty())
			std::cout << "Darkest secret can't be blank" << std::endl;
		else
		{
			_darkestSecret = input;
			break;
		}
	}
	while (true);
}

void	Contact::setContact()
{
	setFirstName();
	setLastName();
	setNickname();
	setPhoneNumber();
	setDarkestSecret();
	std::cout << "New contact added!" << std::endl;
}
