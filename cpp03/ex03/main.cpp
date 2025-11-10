/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:42:56 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/10 11:10:16 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n=== ClapTrap Tests ===" << std::endl;
	{
		ClapTrap	ct("CLAP-TRAP");
		ct.attack("Test Target");
		ct.takeDamage(5);
		ct.beRepaired(3);
		ct.takeDamage(15);
		ct.beRepaired(5);
	}

	std::cout << "\n=== ScavTrap Tests ===" << std::endl;
	{
		ScavTrap	st("SCAV-TRAP");
		st.attack("Bandit");
		st.takeDamage(30);
		st.beRepaired(20);
		st.guardGate();
	}

	std::cout << "\n=== FragTrap Tests ===" << std::endl;
	{
		FragTrap	ft("FRAG-TRAP");
		ft.attack("Robot");
		ft.takeDamage(50);
		ft.beRepaired(25);
		ft.highFivesGuys();
	}

	std::cout << "\n=== DiamondTrap Tests ===" << std::endl;
	{
		DiamondTrap	dt("DIAMOND-TRAP");
		dt.attack("Hunter");
		dt.takeDamage(40);
		dt.beRepaired(10);
		dt.whoAmI();
		dt.highFivesGuys();
		dt.guardGate();
	}

	std::cout << "\n=== Copy & Assignment Tests ===" << std::endl;
	{
		DiamondTrap	orig("OG");
		DiamondTrap	copy(orig);
		DiamondTrap	assign("Temp");

		orig.attack("Guy");
		copy.whoAmI();
		assign.whoAmI();
	}

	std::cout << "\n=== End of Tests ===" << std::endl;
	return (0);
}
