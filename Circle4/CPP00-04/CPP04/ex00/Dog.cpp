/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:46:17 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/25 13:46:17 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Dog::~Dog() {}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
