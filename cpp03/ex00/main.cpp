/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:42:56 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/07 18:52:31 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Test");
	ClapTrap	b("Bot");

	a.attack("Bot");
	b.takeDamage(3);
	b.beRepaired(2);
	b.attack("Caio");
	a.takeDamage(5);
	return (0);
}
