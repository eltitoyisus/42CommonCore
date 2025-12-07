/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:45:11 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/23 12:39:30 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./convert <value>" << std::endl;
		return 1;
	}
	std::string input(argv[1]);
	ScalarConverter::convert(input);
	return 0;
}
