/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:40:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/27 21:14:21 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	checkExecutionRequirements(executor);

	std::cout << "BZZZZZZZZZZZZZ" << std::endl;
	std::cout << "BZZZZZZZZZZZZZ" << std::endl;

	if (rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
