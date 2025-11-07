/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:22:49 by caide-so          #+#    #+#             */
/*   Updated: 2025/11/07 11:45:23 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(float const x, float const y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		~Point();

		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
