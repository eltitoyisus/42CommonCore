/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:02:17 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 13:02:17 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default robot") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!getSigned())
		throw std::runtime_error("Form not signed");
	if (executor.getGrade() > getExec())
		throw GradeTooLowException();

	std::cout << "Drilling noises..." << std::endl;
	srand(time(NULL));
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully 50% of the time" << std::endl;
	} else {
		throw Robotomy();
	}
}

RobotomyRequestForm::~RobotomyRequestForm() {}

const char *Robotomy::what() const throw() {
	return("Robotomy failed");
}
