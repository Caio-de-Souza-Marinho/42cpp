/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:57:01 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/10 21:05:07 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	brain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();

		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif
