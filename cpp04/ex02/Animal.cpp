/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:06:54 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/11 16:21:07 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("")
{
	std::cout << "Animal default constructor called." << std::endl;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal copy constructor called." << std::endl;
	*this = other;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called." << std::endl;
}

const std::string&	Animal::getType() const
{
	return (type);
}
