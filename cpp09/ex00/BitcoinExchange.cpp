/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 22:54:57 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/09 23:23:44 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open the database file.");

	std::string	line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream	ss(line);
		std::string		date;
		std::string		valueStr;
		double			value;

		if (!std::getline(ss, date, ','))
			continue ;
		if (!std::getline(ss, valueStr))
			continue ;

		value = std::strtod(valueStr.c_str(), NULL);
		_data[date] = value;
	}

	if (_data.empty())
		throw std::runtime_error("Error: database is empty.");
}
		
double	BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it;

	if (_data.empty())
		throw std::runtime_error("Error: database is empty.");

	it = _data.lower_bound(date);

	if (it != _data.end() && it->first == date)
		return it->second;

	if (it == _data.begin())
		throw std::runtime_error("Error: no rate available for this date.");

	--it;

	return (it->second);
}

void	BitcoinExchange::processInputFile(const std::string &filename) const
{
	std::ifstream	file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open the input file.");

	std::string	line;

	if (!std::getline(file, line) || trim(line) != "date | value")
		throw std::runtime_error("Error: bad input file header.");

	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		
		size_t	pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		std::string	date = trim(line.substr(0, pos));
		std::string	valueStr = trim(line.substr(pos + 1));
		double		value;

		
		if (!isValidDate(date) || !isValidNumber(valueStr, value))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}

		if (value < 0 || (!valueStr.empty() && valueStr[0] == '-'))
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}

		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}

		try
		{
			double	rate = getRate(date);
			std::cout << date 
				<< " => " 
				<< valueStr 
				<< " = " 
				<< value * rate << std::endl;
		}
		catch (std::exception &e)
	 	{
			std::cout << e.what() << std::endl;
		}
	}
}

std::string	BitcoinExchange::trim(const std::string &str)
{
	size_t	start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");

	size_t	end = str.find_last_not_of(" \t");

	return (str.substr(start, end - start + 1));
}

bool	BitcoinExchange::isValidDate(const std::string &date)
{
	if (date.length() != 10)
		return (false);

	if (date[4] != '-' || date[7] != '-')
		return (false);

	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!isdigit(date[i]))
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return (false);

	int	daysInMonth[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	bool	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	if (leap)
		daysInMonth[1] = 29;

	if (day < 1 || day > daysInMonth[month - 1])
		return (false);

	return (true);
}

bool	BitcoinExchange::isValidNumber(const std::string &str, double &value)
{
	if (str.empty())
		return (false);

	if (str.find('e') != std::string::npos || str.find('E') != std::string::npos)
		return (false);

	for (size_t i = 0; i < str.length(); i++)
	{
		if (!(isdigit(str[i]) || str[i] == '.' || (i == 0 && str[i] == '-')))
			return (false);
	}

	int	dots = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			dots++;
	}
	if (dots > 1)
		return (false);

	char	*end;
	value = std::strtod(str.c_str(), &end);

	if (*end != '\0')
		return (false);

	if (std::isnan(value) || std::isinf(value))
		return (false);
	
	return (true);
}
