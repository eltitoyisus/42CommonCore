/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:31:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/15 22:31:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

MateriaSource::MateriaSource() : _count(0) {
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	_count = other._count;
	for (int i = 0; i < 4; ++i) // if other._inventory = true clone, if false, _inventory = NULL
		_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; ++i) {
			delete _inventory[i];
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : NULL;
		}
		_count = other._count;
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i)
		delete _inventory[i];
}

void MateriaSource::learnMateria(AMateria* m) {
	if (_count < 4 && m)
		_inventory[_count++] = m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _count; ++i) {
		if (_inventory[i] && _inventory[i]->getType() == type)
			return _inventory[i]->clone();
	}
	return NULL;
}
