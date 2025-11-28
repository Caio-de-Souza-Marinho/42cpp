/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 00:39:46 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/28 02:02:09 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class	Intern
{
	private:
		AForm*	createShrubberyCreationForm(const std::string &target);
		AForm*	createRobotomyRequestForm(const std::string &target);
		AForm*	createPresidentialPardonForm(const std::string &target);

		struct	FormEntry
		{
			std::string	name;
			AForm *(Intern::*creator)(std::string const &target);
		};

	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(std::string formName, std::string target);
};

#endif
