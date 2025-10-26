/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:11:37 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/14 21:23:46 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class	Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);

	private:
		std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
