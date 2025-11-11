/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:30:36 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/11 12:20:13 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called." << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called." << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called." << std::endl;
	if (this != &other)
	{
		type = other.type;
		if (brain)
			*brain = *other.brain;
		else
			brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
	delete brain;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return (brain);
}
