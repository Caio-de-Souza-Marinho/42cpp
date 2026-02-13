/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 07:45:29 by caide-so          #+#    #+#             */
/*   Updated: 2026/02/13 07:45:37 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <exception>
#include <iostream>
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &other) : _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return (*this);
}

RPN::~RPN() {}

void	RPN::evaluate(const std::string &expr)
{
	while (!_stack.empty())
		_stack.pop();

	std::stringstream	ss(expr);
	std::string		token;

	try
	{
		while (ss >> token)
			processToken(token);

		if (_stack.size() != 1)
			throw std::runtime_error("Error");

		std::cout << _stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error\n";
	}
}

void	RPN::processToken(const std::string &token)
{
	if (token.length() != 1)
		throw std::runtime_error("Error");

	char	c = token[0];
	
	if (isdigit(c))
	{
		_stack.push(c - '0');
		return ;
	}

	if (!isOperator(c))
		throw std::runtime_error("Error");
	applyOperator(c);
}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");

	int	b = _stack.top();
	_stack.pop();

	int	a = _stack.top();
	_stack.pop();

	int	result;

	switch(op)
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error");
			result = a / b;
			break;
		}
		_stack.push(result);
}
