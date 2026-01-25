/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 21:14:57 by caide-so          #+#    #+#             */
/*   Updated: 2026/01/21 01:34:05 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <climits>
#include <cmath>
#include <iostream>
#include <cctype>
#include <cstdlib>

enum	LiteralType
{
	LIT_SPECIAL,
	LIT_CHAR,
	LIT_INT,
	LIT_FLOAT,
	LIT_DOUBLE,
	LIT_INVALID
};

static LiteralType	identify(std::string const &literal);
static bool		checkSpecial(std::string const &literal);
static bool		checkInt(std::string const &literal);
static bool		checkFloat(std::string const &literal);
static bool		checkDouble(std::string const &literal);
static void		conversionDispatch(std::string const &literal, LiteralType type);
static void		convertFromChar(char value);
static void		convertFromInt(int value);
static void		convertFromFloat(float value);
static void		convertFromDouble(double value);
static void		convertSpecial(std::string const &literal);

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
	return ;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

void	ScalarConverter::convert(std::string const &literal)
{
	LiteralType	type;

	type = identify(literal);
	conversionDispatch(literal, type);
}

static LiteralType	identify(std::string const &literal)
{
	if (checkSpecial(literal))
		return (LIT_SPECIAL);
	unsigned char	c;
	if (literal.length() == 1)
	{
		c = static_cast<unsigned char>(literal[0]);
		if (std::isprint(c) && !std::isdigit(c))
			return (LIT_CHAR);
	}
	if (checkInt(literal))
		return (LIT_INT);
	if (checkFloat(literal))
		return (LIT_FLOAT);
	if (checkDouble(literal))
		return (LIT_DOUBLE);

	return (LIT_INVALID);
}

static bool	checkSpecial(std::string const &literal)
{
	if (literal.empty())
		return (false);

	std::string	specials[8] = {"nan", "nanf", "inf", "+inf", "-inf", "inff", "+inff", "-inff"};

	for (int i = 0; i < 8; i++)
	{
		if (specials[i] == literal)
			return (true);
	}
	return (false);
}

static bool	checkInt(std::string const &literal)
{
	if (literal.empty())
		return (false);

	unsigned char	c;
	size_t		i = 0;
	size_t		len = literal.length();
	bool		hasDigit = false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	while (i < len)
	{
		c = static_cast<unsigned char>(literal[i]);
		if (std::isdigit(c))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDigit);
}

static bool	checkFloat(std::string const &literal)
{
	if (literal.empty())
		return (false);

	unsigned char	c;
	size_t		i = 0;
	size_t		len = literal.length();
	bool		hasDot = false;
	bool		hasDigit = false;

	if (len < 2 || literal[len - 1] != 'f')
		return (false);

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	while (i < len - 1)
	{
		c = static_cast<unsigned char>(literal[i]);
		if (literal[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(c))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDigit);
}

static bool	checkDouble(std::string const &literal)
{
	if (literal.empty())
		return (false);

	unsigned char	c;
	size_t		i = 0;
	size_t		len = literal.length();
	bool		hasDot = false;
	bool		hasDigit = false;

	if (literal[i] == '+' || literal[i] == '-')
		i++;

	while (i < len)
	{
		c = static_cast<unsigned char>(literal[i]);
		if (literal[i] == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(c))
			hasDigit = true;
		else
			return (false);
		i++;
	}
	return (hasDigit && hasDot);
}

static void	conversionDispatch(std::string const &literal, LiteralType type)
{
	long	l;

	switch (type)
	{
		case LIT_SPECIAL:
			convertSpecial(literal);
			break;
		case LIT_CHAR:
			convertFromChar(literal[0]);
			break;
		case LIT_INT:
			l = std::strtol(literal.c_str(), NULL, 10);
			if (l < INT_MIN || l > INT_MAX)
				convertFromDouble(static_cast<double>(l));
			else
				convertFromInt(static_cast<int>(l));
			break;
		case LIT_FLOAT:
			convertFromFloat(static_cast<float>(atof(literal.c_str())));
			break;
		case LIT_DOUBLE:
			convertFromDouble(atof(literal.c_str()));
			break;
                case LIT_INVALID:
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: impossible\n";
			std::cout << "double: impossible\n";
                  	break;
                }
}

static void	convertFromChar(char value)
{
	int	i;
	float	f;
	double	d;

	i = static_cast<int>(value);
	f = static_cast<float>(value);
	d = static_cast<double>(value);


	if (i < 0 || i > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(value)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << value << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

static void	convertFromInt(int value)
{
	char	c;
	float	f;
	double	d;

	c = static_cast<char>(value);
	f = static_cast<float>(value);
	d = static_cast<double>(value);

	if (value < 0 || value > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << value << "\n";
	std::cout << "float: " << f << ".0f\n";
	std::cout << "double: " << d << ".0\n";
}

static void	convertFromFloat(float value)
{
	char	c;
	int	i;
	double	d;

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << value << "f\n";
		std::cout << "double: " << static_cast<double>(value) << "\n";
		return ;
	}

	c = static_cast<char>(value);
	i = static_cast<int>(value);
	d = static_cast<double>(value);

	if (value < 0 || value > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";

	if (value < static_cast<float>(INT_MIN) || value > static_cast<float>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";

	if (value == std::floor(value))
		std::cout << "float: " << value << ".0f\n";
	else
		std::cout << "float: " << value << "f\n";

	if (value == std::floor(d))
		std::cout << "double: " << d << ".0\n";
	else
		std::cout << "double: " << d << "\n";
}


static void	convertFromDouble(double value)
{
	char	c;
	int	i;
	float	f;

	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << static_cast<float>(value) << "f\n";
		std::cout << "double: " << value << "\n";
		return ;
	}

	c = static_cast<char>(value);
	i = static_cast<int>(value);
	f = static_cast<float>(value);

	if (value < 0 || value > 127)
		std::cout << "char: impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(c)))
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: '" << c << "'\n";

	if (value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << i << "\n";

	if (value == std::floor(f))
		std::cout << "float: " << f << ".0f\n";
	else
		std::cout << "float: " << f << "f\n";

	if (value == std::floor(value))
		std::cout << "double: " << value << ".0\n";
	else
		std::cout << "double: " << value << "\n";
}

static void	convertSpecial(std::string const &literal)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";

	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
	else if (literal == "inf" || literal == "inff")
	{
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
	}
}
