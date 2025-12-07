/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:03:20 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:03:20 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main() {
	int a = 14;
	int b = 55;

	::swapV(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::minV(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::maxV(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swapV(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::minV(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::maxV(c, d) << std::endl;
}
