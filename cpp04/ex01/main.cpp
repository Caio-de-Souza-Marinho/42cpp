/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:52:15 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/11 12:20:44 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n==================== Test 1 ====================" << std::endl;
	{
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();

		delete dog;
		delete cat;
	}

	std::cout << "\n==================== Test 2 ====================" << std::endl;
	{
		const Animal*	animals[4];
		animals[0] = new Dog();
		animals[1] = new Dog();
		animals[2] = new Cat();
		animals[3] = new Cat();

		for (int i = 0; i < 4; i++)
			animals[i]->makeSound();

		for (int i = 0; i < 4; i++)
			delete animals[i];
	}

	std::cout << "\n==================== Test 3 ====================" << std::endl;
	{
		Dog	original;
		original.getBrain()->setIdea(0, "Chase the cat!");
		original.getBrain()->setIdea(1, "Eat the bone!");

		Dog	copy(original);

		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;

		// Modifying the copy's brain to confirm they are independent
		copy.getBrain()->setIdea(0, "Sleep all day.");

		std::cout << "After modification:" << std::endl;
		std::cout << "Original idea 0: " << original.getBrain()->getIdea(0) << std::endl;
		std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;

	}

	std::cout << "\n==================== Test 4 ====================" << std::endl;
	{
		Cat	a;
		a.getBrain()->setIdea(0, "Nap on the keyboard.");

		Cat	b;
		b = a;

		std::cout << "Cat a idea: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat b idea: " << b.getBrain()->getIdea(0) << std::endl;

		// Modifying the b's brain to confirm they are independent
		b.getBrain()->setIdea(0, "Knock over a glass.");

		std::cout << "After modification:" << std::endl;
		std::cout << "CAt a idea 0: " << a.getBrain()->getIdea(0) << std::endl;
		std::cout << "Cat b idea 0: " << b.getBrain()->getIdea(0) << std::endl;
	}

	std::cout << "\n==================== Test 5 ====================" << std::endl;
	{
		const Animal*	animal = new Dog();
		delete animal;
	}

	return (0);
}
