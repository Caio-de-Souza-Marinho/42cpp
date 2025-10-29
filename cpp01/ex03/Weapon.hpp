/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:36:13 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/29 19:57:47 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP

class	Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		const std::string&	getType() const;
		void			setType(const std::string& newType);
};

#endif
