/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:11:38 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/28 00:11:51 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n---- Creating Bureaucrats ----\n";
	Bureaucrat	alice("Alice", 1);
	Bureaucrat	bob("Bob", 140);
	Bureaucrat	tom("Tom", 50);

	std::cout << "\n---- Creating Forms ----\n";
	ShrubberyCreationForm	shrub("home");
	RobotomyRequestForm	robo("Bender");
	PresidentialPardonForm	pardon("Ford Prefect");

	std::cout << "\n---- Trying to execute unsigned forms ----\n";
	bob.executeForm(shrub);
	tom.executeForm(robo);
	alice.executeForm(pardon);

	std::cout << "\n---- Signing forms ----\n";
	bob.signForm(shrub);
	tom.signForm(robo);
	alice.signForm(pardon);

	std::cout << "\n---- Executing forms (success tests) ----\n";
	bob.executeForm(shrub);
	tom.executeForm(robo);
	alice.executeForm(pardon);

	std::cout << "\n---- Failure: executing with low grade ----\n";
	bob.executeForm(pardon);

	std::cout << "\n---- Multiple Robotomy Tests (show randomness) ----\n";
	for (int i = 0; i < 6; i++)
		tom.executeForm(robo);

	return (0);
}
