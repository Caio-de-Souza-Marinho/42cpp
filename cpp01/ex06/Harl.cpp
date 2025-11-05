/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:14:19 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/05 12:06:46 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {};
Harl::~Harl() {};

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" ;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	std::string	levelName[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcPtr[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int		levelIndex = -1;
	for (int i = 0; i < 4; i++)
		if (level == levelName[i])
			levelIndex = i;
	switch (levelIndex)
	{
		case 0:
			(this->*funcPtr[0])();
			/* fall through */
		case 1:
			(this->*funcPtr[1])();
			/* fall through */
		case 2:
			(this->*funcPtr[2])();
			/* fall through */
		case 3:
			(this->*funcPtr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
