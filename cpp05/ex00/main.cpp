/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:11:38 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/14 19:12:05 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

static void	testConstructor();
static void	testIncrementDecrement();
static void	testCopyAndAssign();

int	main()
{
	testConstructor();
	testIncrementDecrement();
	testCopyAndAssign();
	return (0);
}

static void	testConstructor()
{
	std::cout << "\n----Constructor Tests ----" << std::endl;

	// Grade too low
	try
	{
		Bureaucrat	bureaucrat("Low", 200);
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Grade too high
	try
	{
		Bureaucrat	bureaucrat("High", 0);
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Normal grade
	try
	{
		Bureaucrat	bureaucrat("Normal", 15);
		std::cout << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

static void	testIncrementDecrement()
{
	std::cout << "\n----Increment and Decrement Tests ----" << std::endl;

	// Increment past upper bound
	try
	{
		Bureaucrat	bureaucrat("Top", 1);
		std::cout << bureaucrat;
		bureaucrat.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Decrement past lower bound
	try
	{
		Bureaucrat	bureaucrat("Bottom", 150);
		std::cout << bureaucrat;
		bureaucrat.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	// Valid grade changes
	try
	{
		Bureaucrat	bureaucrat("Valid", 43);
		std::cout << "[Before] " << bureaucrat;
		bureaucrat.incrementGrade();
		bureaucrat.incrementGrade();
		bureaucrat.decrementGrade();
		std::cout << "[After ] " << bureaucrat;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

static void	testCopyAndAssign()
{
	std::cout << "\n----Copy and Assignment Tests ----" << std::endl;

	try
	{
		Bureaucrat	original("Original", 10);
		std::cout << "[Original] " << original;

		// Copy constructor
		Bureaucrat	copy(original);
		std::cout << "[Copy    ] " << copy;

		// Assignment
		Bureaucrat	assigned("Temp", 100);
		std::cout << "[Before  ] " << assigned;
		assigned = original;
		std::cout << "[After   ] " << assigned;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
