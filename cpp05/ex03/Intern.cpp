/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:57:35 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/28 02:10:45 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);	
}

Intern::~Intern() {}

AForm*	Intern::createShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string formName, std::string target)
{
	FormEntry	entries[3] =
	{
		{"shrubbery creation", &Intern::createShrubberyCreationForm},
		{"robotomy request", &Intern::createRobotomyRequestForm},
		{"presidential pardon", &Intern::createPresidentialPardonForm}
	};

	for (int i = 0; i < 3; i++)
	{
		if (entries[i].name == formName)
		{
			std::cout << "Intern creates " << formName << " form." << std::endl;
			return (this->*(entries[i].creator))(target);
		}
	}

	std::cout << "Intern: form '" << formName << "' does not exist." << std::endl;
	return (NULL);
}
