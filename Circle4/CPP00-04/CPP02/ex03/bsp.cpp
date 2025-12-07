/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 21:34:26 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/13 21:34:26 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	// a,b,c vertices to triangle

	// pooint -> the point to check

	// returns true if point is inside triangle, otherwise false
	// if the point is on an endege return false
	float areaABC = area(a, b, c);
	float areaPBC = area(point, b, c);
	float areaAPC = area(a, point, c);
	float areaABP = area(a, b, point);

	if (areaPBC == 0.0f || areaAPC == 0.0f || areaABP == 0.0f)
		return false;
	const float epsilon = 0.0001f;
	return fabs(areaABC - (areaPBC + areaAPC + areaABP)) < epsilon;
}
