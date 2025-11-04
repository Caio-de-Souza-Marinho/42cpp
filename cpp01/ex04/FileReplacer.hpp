/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:09:16 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/04 11:32:42 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

class	FileReplacer
{
	private:
		std::string	_infile;
		std::string	_outfile;
		std::string	_s1;
		std::string	_s2;

	public:
		FileReplacer(std::string infile, std::string s1, std::string s2);
		void	replace(void);
};

#endif
