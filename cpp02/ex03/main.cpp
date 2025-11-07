/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:25:25 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/07 14:45:26 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point const	a(0, 0);
	Point const	b(20, 0);
	Point const	c(10, 30);
	
	Point const	points[] =
	{
		Point(10, 15),	// inside
		Point(15, 10),	// inside
		Point(5, 5),	//inside
		Point(10, 30),	//vertex = outside
		Point(0, 0),	//vertex = outside
		Point(20, 0),	//vertex = outside
		Point(25, 5),	// outside
		Point(10, -5),	// outside
		Point(5, 25),	// outside
	};

	int	i = 0;
	while (i < 9)
	{
		std::cout << "Point (" << points[i].getX().toFloat() <<  ", " << points[i].getY().toFloat() << ") -> ";
		if (bsp(a, b, c, points[i]))
			std::cout << "Inside" << std::endl;
		else 
			std::cout << "Outside" << std::endl;
		i++;
	}
	return (0);
}
