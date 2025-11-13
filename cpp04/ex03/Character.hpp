/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:33:24 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/12 18:38:32 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_inventory[4];

	public:
		Character();
		Character(const Character &other);
		Character &operator=(const Character &other);
		~Character();

		Character(std::string name);

		std::string const&	getName() const;
		void			equip(AMateria* m);
		void			unequip(int idx);
		void			use(int idx, ICharacter& target);
};

#endif
