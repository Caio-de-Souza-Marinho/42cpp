/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:58:49 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/11 16:21:03 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		virtual void		makeSound() const = 0;
		const std::string&	getType() const;
};

#endif
