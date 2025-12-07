/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:02:22 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 19:02:22 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {

	}
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == names[i]) {
			for (int j = 0; j < 3; ++j) {
				if (j != i)
					delete forms[j];
			}
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i];
		}
	}

	for (int i = 0; i < 3; ++i) {
		delete forms[i];
	}
	std::cout << "Unknown form type: " << formName << std::endl;
	return NULL;
}
