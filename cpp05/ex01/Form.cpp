/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 16:40:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/21 16:44:59 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default_form"),
	_isSigned(false),
	_gradeRequiredToSign(150),
	_gradeRequiredToExecute(150)
{}

Form::Form(const Form &other)
	: _name(other._name),
	_isSigned(other._isSigned),
	_gradeRequiredToSign(other._gradeRequiredToSign),
	_gradeRequiredToExecute(other._gradeRequiredToExecute)
{}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form() {}

Form::Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute)
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

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}
int	Form::getGradeRequiredToSign() const
{
	return (_gradeRequiredToSign);
}
int	Form::getGradeRequiredToExecute() const
{
	return (_gradeRequiredToExecute);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_isSigned)
		throw std::runtime_error("Form already signed");
	if (bureaucrat.getGrade() > _gradeRequiredToSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high.");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low.");
}

std::ostream &operator<<(std::ostream &out, const Form &value)
{
	out << "Form: " << value.getName() << std::endl
		<< "Grade to sign: " << value.getGradeRequiredToSign() << std::endl
		<< "Grade to execute: " << value.getGradeRequiredToExecute() << std::endl
		<< "Is: " << (value.getIsSigned() ? "signed" : "not signed") << std::endl;
	return (out);
}
