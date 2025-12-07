/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 23:05:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/07 23:05:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// <name> attacks with their <weapon type>

// humanA takes weapon in constructor B does not

// humanB can be unarmed, but humanA has always to be armed

Weapon::Weapon(std::string weapon)
{
	setType(weapon);
}

void Weapon::setType(std::string type)
{
	_type = type;
}

const std::string &Weapon::getType() const
{
	return this->_type;
}

Weapon::~Weapon()
{
}
