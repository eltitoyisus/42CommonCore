/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:42:41 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/16 15:58:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("Unknown") {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const & type) : _type(type) {}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Using AMateria of type " << _type << " on " << target.getName() << "." << std::endl;
}
