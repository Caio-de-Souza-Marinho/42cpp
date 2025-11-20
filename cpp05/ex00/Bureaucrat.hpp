/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:12:24 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/19 21:31:09 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class	Bureaucrat
{
	private:
		const std::string	_name;
		int			_grade;

	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(std::string name, int grade);
		
		const std::string	getName() const;
		int			getGrade() const;
		void			incrementGrade();
		void			decrementGrade();

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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);

#endif
