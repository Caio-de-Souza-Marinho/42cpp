/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:46:29 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/14 11:18:13 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
	std::cout << "Cure copy constructor called." << std::endl;
	*this = other;
}

Cure	&Cure::operator=(const Cure &other)
{
	std::cout << "Cure copy assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called." << std::endl;
}

AMateria*	Cure::clone() const
{
	AMateria*	m = new Cure();
	return (m);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals the wounds of " << target.getName() << " *" << std::endl;
}
