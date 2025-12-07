/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:33:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 11:33:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScav") {
	std::cout << "🔨 ScavTrap plain constructor called 🔨" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "🔨 ScavTrap default constructor called 🔨" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other) {
	std::cout << "🔨 ScavTrap copy constructor called 🔨" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "🔨 ScavTrap assignment operator called 🔨" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "❌ ScavTrap destructor called ❌" << std::endl;
}

void ScavTrap::guardGate() {
	if (_hitPoints <= 0) {
		std::cout << "Blud is dead, he ain't doin that" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "Let him rest!!! He has to recoves hes inner energy!!!!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "🛡️ ScavTrap <" << _name << "> is now in Gate keeper mode 🛡️" << std::endl;
}
