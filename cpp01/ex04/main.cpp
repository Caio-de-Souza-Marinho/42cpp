/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:34:01 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/04 11:34:13 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sedisforlosers <filename> s1 s2" << std::endl;
		return (1);
	}
	FileReplacer	replacer(argv[1], argv[2], argv[3]);
	replacer.replace();
	return (0);
}
