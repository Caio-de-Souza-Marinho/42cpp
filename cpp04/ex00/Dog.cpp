/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:30:36 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/10 18:48:32 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	type = "Dog";
	std::cout << "Dog default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other)
		type = other.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}
