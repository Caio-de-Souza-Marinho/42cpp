/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:49:56 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/07 14:43:55 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float	area(Point const p1, Point const p2, Point const p3);

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area0 = area(a, b, c);
	float	area1 = area(point, a, b);
	float	area2 = area(point, b, c);
	float	area3 = area(point, a, c);
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	return (roundf(area0 * 1000) == roundf((area1 + area2 + area3) * 1000));
}

float	area(Point const p1, Point const p2, Point const p3)
{
	Fixed	area = (p1.getX() * (p2.getY() - p3.getY()) +
			p2.getX() * (p3.getY() - p1.getY()) +
			p3.getX() * (p1.getY() - p2.getY()))/2;
	float	result = area.toFloat();
	if (result < 0)
		result = -result;
	return (result);
}
