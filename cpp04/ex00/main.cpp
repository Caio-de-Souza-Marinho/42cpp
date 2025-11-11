/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:52:15 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/10 20:55:19 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	hearAnimal(const Animal& a);

int	main(void)
{
	std::cout << "\n==================== Test 1 ====================" << std::endl;
	{
		const Animal*	animal = new Animal();
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}

	std::cout << "\n==================== Test 2 ====================" << std::endl;
	{
		const Animal*	animals[3];
		animals[0] = new Animal();
		animals[1] = new Dog();
		animals[2] = new Cat();

		for (int i = 0; i < 3; i++)
			animals[i]->makeSound();

		for (int i = 0; i < 3; i++)
			delete animals[i];
	}

	std::cout << "\n==================== Test 3 ====================" << std::endl;
	{
		Dog	originalDog;
		Dog	copiedDog(originalDog);
		Dog	assignedDog;
		assignedDog = originalDog;

		std::cout << originalDog.getType() << std::endl;
		std::cout << copiedDog.getType() << std::endl;
		std::cout << assignedDog.getType() << std::endl;
	}

	std::cout << "\n==================== Test 4 ====================" << std::endl;
	{
		// Local (stack) objects
		Animal	animal;
		Dog	dog;
		Cat	cat;

		std::cout << "\n-- Polymorphism through references --" << std::endl;
		hearAnimal(animal);
		hearAnimal(dog);
		hearAnimal(cat);

		std::cout << "\n-- Polymorphism through base pointers --" << std::endl;
		const Animal*	ptrDog = &dog;
		const Animal*	ptrCat = &cat;
		const Animal*	ptrAnimal = &animal;

		ptrDog->makeSound();
		ptrCat->makeSound();
		ptrAnimal->makeSound();
	}

	std::cout << "\n==================== Test 5 ====================" << std::endl;
	{
		const WrongAnimal*	wrongCat = new WrongCat();
		wrongCat->makeSound();
		delete wrongCat;
	}

	return (0);
}

void	hearAnimal(const Animal& a)
{
	a.makeSound();
}
