/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:52:20 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/04 11:52:20 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Constructor

Zombie::Zombie()
{

}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	// std::cout << "Zombie: " << _name << " created" << std::endl;
}

void Zombie::announce(int i, std::string name)
{
	std::cout << name << "[" << i << "]" 
				<< "isssssss aliveeeeeeee" << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	// std::cout << "Zombie: " << _name << " destroyed" << std::endl;
}
