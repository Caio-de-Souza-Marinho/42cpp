/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:21:01 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/21 16:25:00 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_gradeRequiredToSign;
		const int		_gradeRequiredToExecute;

	public:
		Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		Form(const std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);

		const std::string	&getName() const;
		bool			getIsSigned() const;
		int			getGradeRequiredToSign() const;
		int			getGradeRequiredToExecute() const;
		void			beSigned(const Bureaucrat &bureaucrat);
		

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
};
std::ostream &operator<<(std::ostream &out, const Form &value);

#endif
