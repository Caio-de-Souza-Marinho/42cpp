/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:54:30 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/12 20:56:16 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character() : _name("")
{
	std::cout << "Character default constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
{
	std::cout << "Character copy constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
      			_inventory[i] = NULL;
	}
	_name = other._name;
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called." << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		_name = other._name;
	}
	return (*this);
}

Character::~Character()
{
	std::cout << "Character destructor called." << std::endl;
	for (int i = 0; i < 4; i++)
      		if (_inventory[i])
	    		delete _inventory[i];

}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character constructor called." << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			break ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid slot index: " << idx << std::endl;
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "No materia equipped in slot " << idx << std::endl;
}
