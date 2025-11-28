/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:40:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/27 19:53:04 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default_form"),
	_isSigned(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{}

AForm::AForm(const AForm &other)
	: _name(other._name),
	_isSigned(other._isSigned),
	_gradeRequiredToSign(other._gradeRequiredToSign),
	_gradeRequiredToExecute(other._gradeRequiredToExecute)
{}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm() {}

AForm::AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute)
	: _name(name),
	_isSigned(false),
	_gradeRequiredToSign(gradeRequiredToSign),
	_gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
		throw GradeTooHighException();
	if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
		throw GradeTooLowException();
}

const std::string	&AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}
int	AForm::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}
int	AForm::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
		return ;
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low.");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed.");
}

void	AForm::checkExecutionRequirements(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeRequiredToExecute)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const AForm &value)
{
	out << "Form: " << value.getName() << std::endl
		<< "Grade to sign: " << value.getGradeRequiredToSign() << std::endl
		<< "Grade to execute: " << value.getGradeRequiredToExecute() << std::endl
		<< "Is: " << (value.getIsSigned() ? "signed" : "not signed") << std::endl;
	return (out);
}
