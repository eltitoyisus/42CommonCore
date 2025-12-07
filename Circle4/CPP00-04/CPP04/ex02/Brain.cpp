/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:49:51 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 19:49:51 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructed" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = "Default idea ";
	}
}

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructed" << std::endl;
	*this = other;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assigned" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destroyed" << std::endl;
}

void Brain::setIdeas(std::string idea) {
	for (int i = 0; i < 100; i++) {
		_ideas[i] = idea;
	}
}

void Brain::getIdeas() {
	std::cout << _ideas[0] << std::endl;
}
