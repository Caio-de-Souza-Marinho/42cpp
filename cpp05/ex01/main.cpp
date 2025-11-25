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
#include "Form.hpp"

int	main()
{
	std::cout << "\n---- TEST 1: Valid signing ----\n";
	Bureaucrat	bob("Bob", 50);
	Form		tax("Tax Form", 75, 75);
	bob.signForm(tax);
	std::cout << tax;

	std::cout << "\n---- TEST 2: Grade too low to sign ----\n";
	Bureaucrat	jim("Jim", 100);
	Form		passport("Passport", 20, 20);
	jim.signForm(passport);
	std::cout << passport;

	std::cout << "\n---- TEST 3: Already signed ----\n";
	Bureaucrat	alice("Alice", 1);
	Form		visa("Visa", 5, 5);
	alice.signForm(visa);
	alice.signForm(visa);
	std::cout << visa;

	std::cout << "\n---- TEST 4: Boundary values ----\n";
	try
	{
		Bureaucrat	chief("Chief", 1);
		Form		topSecret("Top Secret", 1, 1);
		chief.signForm(topSecret);
		std::cout << topSecret;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}

	std::cout << "\n---- TEST 5: Invalid Form creation (grade too high) ----\n";
	try
	{
		Form invalid1("Invalid1", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n---- TEST 6: Invalid Form creation (grade too low) ----\n";
	try
	{
		Form invalid2("Invalid2", 10, 200);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
