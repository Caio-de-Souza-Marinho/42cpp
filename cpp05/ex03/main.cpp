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
#include "Intern.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n---- Creating Intern ----\n";
	Intern	intern;
	
	std::cout << "\n---- Intern creating forms ----\n";
	AForm*	f1 = intern.makeForm("shrubbery creation", "garden");
	AForm*	f2 = intern.makeForm("robotomy request", "Marvin");
	AForm*	f3 = intern.makeForm("presidential pardon", "President");
	AForm*	invalid = intern.makeForm("unknown form", "nobody");

	std::cout << "\n---- Creating Bureaucrats ----\n";
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	mid("Mid", 50);
	Bureaucrat	low("Low", 150);

	std::cout << "\n---- Signing Forms ----\n";
	if (f1)
		low.signForm(*f1);
	if (f2)
		mid.signForm(*f2);
	if (f3)
		boss.signForm(*f3);

	std::cout << "\n---- Executing Forms ----\n";
	if (f1)
		low.executeForm(*f1);
	if (f1)
		mid.executeForm(*f1);
	if (f1)
		boss.executeForm(*f1);

	if (f2)
		low.executeForm(*f2);
	if (f2)
		mid.executeForm(*f2);
	if (f2)
		boss.executeForm(*f2);

	if (f3)
		low.executeForm(*f3);
	if (f3)
		mid.executeForm(*f3);
	if (f3)
		boss.executeForm(*f3);

	std::cout << "\n---- Cleaning up ----\n";
	delete f1;
	delete f2;
	delete f3;
	delete invalid;

	return (0);
}
