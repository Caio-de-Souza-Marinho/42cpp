/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:12:39 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/04 11:33:01 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string infile, std::string s1, std::string s2)
{
	_infile = infile;
	_outfile = infile + ".replace";
	_s1 = s1;
	_s2 = s2;
}

void	FileReplacer::replace(void)
{
	std::fstream	file(_infile.c_str());
	if (!file.is_open())
	{
		std::cout << "Failed to open input file." << std::endl;
		return ;
	}

	std::ofstream	outfile(_outfile.c_str());
	if (!outfile.is_open())
	{
		std::cout << "Failed to create output file." << std::endl;
		file.close();
		return ;
	}

	std::string	line;
	std::size_t	s1_len = _s1.length();

	while (std::getline(file, line))
	{
		std::string	line_replace = "";
		std::size_t	pos_start = 0;
		std::size_t	pos_found = 0;
		
		while (true)
		{
			pos_found = line.find(_s1, pos_start);
			if (pos_found == std::string::npos)
			{
				line_replace += line.substr(pos_start);
				break;
			}
			line_replace += line.substr(pos_start, pos_found - pos_start);
			line_replace += _s2;
			pos_start = pos_found + s1_len;
		}
		outfile << line_replace << std::endl;
	}
	file.close();
	outfile.close();
}
