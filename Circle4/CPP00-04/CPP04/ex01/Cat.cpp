/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 08:32:37 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/15 08:32:37 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructed with a brain!!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}


void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdeas(const std::string idea) {
	_brain->setIdeas(idea);
}

void Cat::getIdea() {
	_brain->getIdeas();
}
