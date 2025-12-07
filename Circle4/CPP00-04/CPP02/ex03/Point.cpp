/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:34:28 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/13 21:34:28 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed& x, const Fixed& y) : _x(x), _y(y) {}

Point::Point(const float a, const float b) : _x(a), _y(b) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		_x = other._x;
		_y = other._y;
	}
	return *this;
}

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}

float area(Point const p1, Point const p2, Point const p3) {
	return fabs((p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
				+ p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
				+ p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))
				) / 2.0f;
}

Point::~Point() {}
