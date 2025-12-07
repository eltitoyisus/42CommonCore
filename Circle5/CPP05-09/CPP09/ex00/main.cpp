/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:12:18 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/21 18:12:18 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	
	BitcoinExchange exchange;
	exchange.loadData("cpp_09/data.csv");
	exchange.processInputFile(argv[1]);
	return 0;
}
