/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:41:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/12 00:45:51 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class	ICharacter;

class	AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		AMateria(std::string const& type);

		std::string const& 	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter&	target);
};

#endif
