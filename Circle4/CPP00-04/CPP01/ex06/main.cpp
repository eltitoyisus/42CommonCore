/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:42:18 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/24 13:42:18 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc == 2)
		harl.complain(argv[1]);
	else
	{
		std::cout << "Invalid arg number" << std::endl;
		std::cout << "USAGE: ./harl <level message>" << std::endl;
	}
}
