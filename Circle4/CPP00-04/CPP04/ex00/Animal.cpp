/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:51:42 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 15:51:42 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	_type = "random animal";
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {}

std::string Animal::getType() const {
	return _type;
}

void Animal::makeSound() const {
	std::cout << "generic animal noise" << std::endl;
}
