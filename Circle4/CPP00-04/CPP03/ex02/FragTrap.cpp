/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:28:58 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 12:28:58 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DefaultFrag") {
	std::cout << "🔨 Default FragTrap constructor called 🔨" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "🔨 Default FragTrap constructor called 🔨" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "🔨 Copy FragTrap constructor called 🔨" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "🔨 FragTrap assignment operator called 🔨" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "❌ FragTrap destructor called ❌" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (_hitPoints <= 0) {
		std::cout << "Blud is dead, he ain't doin that" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "Let him rest!!! He has to recoves hes inner energy!!!!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "FragTrap <" << _name << "> is requesting a high five!!" << std::endl;
}
