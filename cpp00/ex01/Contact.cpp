/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 00:59:54 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/09 03:07:49 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include <iostream>
#include "Contact.hpp"

static bool		isValidName(std::string input);
static std::string	trim(std::string str);
static std::string	capitalize(std::string str);
static bool		isValidPhone(std::string input);

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
			input = trim(input);
			if (isValidName(input))
			{
				input = capitalize(input);
				_firstName = input;
				break;
			}
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
			input = trim(input);
			if (isValidName(input))
			{
				input = capitalize(input);
				_lastName = input;
				break;
			}
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
			input = trim(input);
			if (isValidName(input))
			{
				input = capitalize(input);
				_nickname= input;
				break;
			}
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
			input = trim(input);
			if (isValidPhone(input))
			{
				_phoneNumber = input;
				break;
			}
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
			input = trim(input);
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

const std::string& Contact::getFirstName() const
{
	return (_firstName);
}

const std::string& Contact::getLastName() const
{
	return (_lastName);
}

const std::string& Contact::getNickname() const
{
	return (_nickname);
}

const std::string& Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

const std::string& Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}

void	Contact::displayFullContact()
{
	std::cout << std::endl << "First name: " + _firstName << std::endl;
	std::cout << "Last name: " + _lastName << std::endl;
	std::cout << "Nickname: " + _nickname << std::endl;
	std::cout << "Phone number: " + _phoneNumber << std::endl;
	std::cout << "Darkest secret: " + _darkestSecret<< std::endl;
}

static bool	isValidName(std::string input)
{
	if (input.length() < 2)
	{
		std::cout << "Name must be at least 2 characters long." << std::endl;
		return (false);
	}
	if (input.length() > 50)
	{
		std::cout << "Name cannot exceed 50 characters." << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isalpha(input[i]) && input[i] != '-' && input[i] != ' ')
		{
			std::cout << "Name can only contain letters, spaces or hyphens." << std::endl;
			return (false);
		}
	}
	return (true);
}

static std::string	trim(std::string str)
{
	size_t	start = str.find_first_not_of(' ');
	size_t	end = str.find_last_not_of(' ');
	if (start == std::string::npos)
		str = "";
	else
		str = str.substr(start, end - start + 1);
	return (str);
}

static std::string	capitalize(std::string str)
{
	if (isalpha(str[0]))
		str[0] = std::toupper(static_cast<unsigned char>(str[0]));
	for (size_t i = 1; i < str.length(); i++)
	{
		if (isalpha(str[i]))
			str[i] = std::tolower(static_cast<unsigned char>(str[i]));
	}
	return (str);
}

static bool	isValidPhone(std::string input)
{
	if (input.length() < 3)
	{
		std::cout << "Phone number must be at least 3 digits long." << std::endl;
		return (false);
	}
	if (input.length() > 50)
	{
		std::cout << "Phone number cannot exceed 20 digits." << std::endl;
		return (false);
	}
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != '-' && input[i] != '+' && input[i] != ' ')
		{
			std::cout << "Phone number can only contain digits, spaces or '+'/'-' symbols." << std::endl;
			return (false);
		}
	}
	return (true);
}
