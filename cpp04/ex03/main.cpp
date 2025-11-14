/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 19:36:43 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/14 12:22:47 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int	main()
{
	std::cout << "\n---- TEST 1: Basic Learning & Creation ----" << std::endl;
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");

	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << "\n---- TEST 2: Using Materias ----" << std::endl;
	ICharacter*	bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n---- TEST 3: Unknown Materia Type ----" << std::endl;
	AMateria*	unknown = src->createMateria("fire");
	if (!unknown)
		std::cout << "Unknown materia type correctly returned NULL" << std::endl;

	std::cout << "\n---- TEST 4: Inventory Full ----" << std::endl;
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	AMateria*	fifth = src->createMateria("ice");
	me->equip(fifth);

	std::cout << "\n---- TEST 5: Unequip ----" << std::endl;
	me->unequip(0);
	me->unequip(1);

	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));

	std::cout << "\n---- TEST 6: MateriaSource Copy ----" << std::endl;
	MateriaSource	copy = *(MateriaSource*)src;
	AMateria*	fromCopy = copy.createMateria("ice");

	if (fromCopy)
		std::cout << "Copy created materia successfully." << std::endl;

	delete fromCopy;

	std::cout << "\n---- TEST 7: Character Copy ----" << std::endl;
	Character	clone(*(Character*)me);
	clone.use(0, *bob);
	clone.use(1, *bob);

	std::cout << "\n---- TEST 8: Using Empty Slots ----" << std::endl;
	me->use(3, *bob);
	me->use(10, *bob);

	std::cout << "\n---- CLEANUP ----" << std::endl;
	delete bob;
	delete me;
	delete src;
	return (0);
}
