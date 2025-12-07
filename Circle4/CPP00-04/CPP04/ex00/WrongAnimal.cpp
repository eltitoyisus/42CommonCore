/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:48:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/25 13:48:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {}

void WrongAnimal::makeSound() const {
	std::cout << "Some wrong generic animal sound" << std::endl;
}

std::string WrongAnimal::getType() const {
	return _type;
}
