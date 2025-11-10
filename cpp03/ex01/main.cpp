/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:42:56 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/10 04:01:52 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	st("SCAV-TRAP");
	st.attack("Bandit");
	st.takeDamage(30);
	st.beRepaired(20);
	st.guardGate();
	return (0);
}
