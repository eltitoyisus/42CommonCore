/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:13:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 13:13:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultDiaClap") {
	std::cout << "🔨 DiamondTrap default constructor called 🔨" << std::endl;
	this->_name = _name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap") {
	std::cout << "🔨 DiamondTrap default constructor called 🔨" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
	std::cout << "🔨 DiamondTrap copye constructor called 🔨" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "🔨 DiamondTrap assingment operator called 🔨" << std::endl;
	this->_name = other._name + "_clap_trap";
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "❌ DiamondTrap destructor called ❌" << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << "DiamondTrap name: " << _name << std::endl;
	std::cout << "DiamondTrap " << "ClapTrap name: " << ClapTrap::_name << std::endl;
}
