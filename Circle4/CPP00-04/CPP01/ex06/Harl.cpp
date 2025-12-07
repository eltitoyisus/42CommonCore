/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hral.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:42:48 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/24 13:42:48 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::_debug(void)
{
	std::cout << "DEBUG MESSAGE" << std::endl << std::endl;
}

void Harl::_info(void)
{
	std::cout << "INFO MESSAGE" << std::endl  << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "WARNING MESSAGE" << std::endl  << std::endl;
}

void Harl::_error(void)
{
	std::cout << "ERROR MESSAGE" << std::endl  << std::endl;
}

void Harl::complain( std::string level )
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while(i < 4)
	{
		if (level == levels[i])
			break;
		i++;
	}
	switch(i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			_debug();
			std::cout << "[ INFO ]" << std::endl;
			_info();
			std::cout << "[ WARNING ]" << std::endl;
			_warning();
			std::cout << "[ ERROR ]" << std::endl;
			_error();
			break;
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			_info();
			std::cout << "[ WARNING ]" << std::endl;
			_warning();
			std::cout << "[ ERROR ]" << std::endl;
			_error();
			break;
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			_warning();
			std::cout << "[ ERROR ]" << std::endl;
			_error();
			break;
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			_error();
			break;
		default:
			std::cout << "Unknown level" << std::endl;
	}
}
