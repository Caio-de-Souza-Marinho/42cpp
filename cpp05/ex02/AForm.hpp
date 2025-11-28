/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:21:01 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/27 20:09:20 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class	Bureaucrat;

class	AForm
{
	protected:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeRequiredToSign;
		const int		_gradeRequiredToExecute;
		void			checkExecutionRequirements(const Bureaucrat &executor) const;

	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		AForm(const std::string &name, int gradeRequiredToSign, int gradeRequiredToExecute);

		const std::string	&getName() const;
		bool			getIsSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;
		void			beSigned(const Bureaucrat &bureaucrat);
		virtual void 		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &value);

#endif
