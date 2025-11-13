/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 00:46:29 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/12 20:12:22 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice &other)
{
	std::cout << "Ice copy constructor called." << std::endl;
	*this = other;
}

Ice	&Ice::operator=(const Ice &other)
{
	std::cout << "Ice copy assignment operator called." << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called." << std::endl;
}

AMateria*	Ice::clone() const
{
	AMateria*	m = new Ice();
	return (m);
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
