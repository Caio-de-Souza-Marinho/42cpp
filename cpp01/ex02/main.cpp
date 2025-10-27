/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:53:13 by caide-so          #+#    #+#             */
/*   Updated: 2025/10/26 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "=============Memory addresses============" << std::endl;
	std::cout << &str << std::endl;;
	std::cout << stringPTR << std::endl;;
	std::cout << &stringREF << std::endl;;
	std::cout << "=============Values============" << std::endl;
	std::cout << str << std::endl;;
	std::cout << *stringPTR << std::endl;;
	std::cout << stringREF << std::endl;;
	return (0);
}
