/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:26:15 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/26 09:26:15 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void) {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point point(6, 5);
	std::cout << "Result: " << std::endl;
	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
