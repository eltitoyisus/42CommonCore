/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:34:29 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/13 21:34:29 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Fixed& x, const Fixed& y);
		Point(const float a, const float b);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

	private:
		Fixed _x;
		Fixed _y;
};

	float area(Point const p1, Point const p2, Point const p3);
