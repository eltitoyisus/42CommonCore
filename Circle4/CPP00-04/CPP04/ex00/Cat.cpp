/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:45:31 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/25 13:45:31 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Cat::~Cat() {}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
