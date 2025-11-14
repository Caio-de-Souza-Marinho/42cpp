/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:51:25 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/14 11:12:40 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE
#define MATERIASOURCE

#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		AMateria*	_inventory[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif
