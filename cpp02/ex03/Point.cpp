/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:27:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/07 11:49:21 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Point::~Point() {}

Fixed const	&Point::getX(void) const
{
	return (this->_x);
}

Fixed const	&Point::getY(void) const
{
	return (this->_y);
}
