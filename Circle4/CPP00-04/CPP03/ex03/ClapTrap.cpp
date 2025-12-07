/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 05:35:24 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 05:35:24 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "🔨 Default constructor called 🔨" << std::endl;
}

ClapTrap::ClapTrap() : _name("default name"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << "🔨 Copy constructor called 🔨" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "🔨 Assingment operator called 🔨" << std::endl;
	if(this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}


// attacking and repairing at the same time const 1 energy point each
// claptrap cant do anything if no energy points
// makes target lose n hit points
void ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap <" << _name << "> is dead and cannot attack!!" << std::endl;
		return;
	}
	else if (_energyPoints <= 0) {
		std::cout << "ClapTrap <" << _name << "> has no energy left to attack!!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap <" << _name << "> attacks <" << target << ">, dealing " << _attackDamage << " points of damage!!" << std::endl;
}

// makes player take attack() damage
void ClapTrap::takeDamage(unsigned int amount) {
	// now it makes damage to the target
	if (_hitPoints > amount)
		_hitPoints -= amount;
	else if (_hitPoints <= 0) {
		std::cout << "ClapTrap <" << _name << "> is already dead!! Let him rest 😔" << std::endl;
		return ;
	}
	else {
		std::cout << "ClapTrap <" << _name << "> is already dead!! Let him rest 😔" << std::endl;
		return ;
	}
	std::cout << "ClapTrap <" << _name << "> has received " << amount << " of damage!!" << std::endl;

}

// lets player regain n hit points
void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap <" << _name << "> is dead!! Cant revive him 🧟" << std::endl;
		return ;
	}
	else if ((_hitPoints + amount) > 10) {
		std::cout << "ClapTrap <" << _name << "> cannot heal for more than 10 hit points!!" << std::endl;
		return ;
	}
	else if (_energyPoints <= 0) {
		std::cout << "ClapTrap <" << _name << "> doesnt have enought energy to heal!!" << std::endl;
		return ;
	}
	else if (_hitPoints > amount) {
		_hitPoints += amount;
		_energyPoints--;
	}
	std::cout << "ClapTrap <" << _name << "> has been damaged for " << amount << " hit points!!" << std::endl;
}

std::string ClapTrap::getName() const {
	return _name;
}

unsigned int ClapTrap::setAttackDamage(unsigned int damage) {
	_attackDamage = damage;
	return _attackDamage;
}

unsigned int ClapTrap::getAttackDamage() {
	return this->_attackDamage;
}

ClapTrap::~ClapTrap() {
	std::cout << "❌ Destructor called ❌" << std::endl;
}
