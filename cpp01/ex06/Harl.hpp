/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 18:03:34 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/05 10:26:52 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#ifndef HARL_HPP
#define HARL_HPP

class	Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
