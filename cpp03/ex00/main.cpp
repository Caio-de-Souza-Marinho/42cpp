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
	ClapTrap	ct("CLAP-TRAP");
	ClapTrap	ct2("Bot");

	ct.attack("Bot");
	ct2.takeDamage(3);
	ct2.beRepaired(2);
	ct2.attack("CLAP-TRAP");
	ct.takeDamage(5);
	return (0);
}
