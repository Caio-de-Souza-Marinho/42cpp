/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 21:17:14 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/10 21:18:16 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();
		
		void		setIdea(int index, const std::string &idea);
		std::string	getIdea(int index) const;
};

#endif
