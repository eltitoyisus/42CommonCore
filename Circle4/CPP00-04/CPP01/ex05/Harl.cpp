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

void Harl::debug(void)
{
	std::cout << "DEBUG MESSAGE" << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO MESSAGE" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING MESSAGE" << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR MESSAGE" << std::endl;
}

void Harl::complain( std::string level )
{
	typedef void (Harl::*Funcs)(void);
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Funcs functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*functions[i])();
			return;
		}
	}
	std::cout << "Unknown level" << std::endl;
}
