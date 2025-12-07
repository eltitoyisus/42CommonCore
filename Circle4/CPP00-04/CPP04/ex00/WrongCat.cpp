/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:49:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/25 13:49:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongCat::~WrongCat() {}

void WrongCat::makeSound() const {
	std::cout << "Meow? (but wrong)" << std::endl;
}
