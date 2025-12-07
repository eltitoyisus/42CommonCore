/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:24:23 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 10:24:23 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default name"), _signGrade(150), _signExec(150) {}

AForm::AForm(const std::string name, const int signGrade, const int signExec)
: _name(name), _signed(false), _signGrade(signGrade), _signExec(signExec) {}

AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _signExec(other._signExec) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

int AForm::getGrade() const {
	return _signGrade;
}

int AForm::getExec() const {
	return _signExec;
}

void AForm::beSigned(const Bureaucrat& b) {
	if ((b.getGrade() <= _signGrade) && (b.getGrade() <= _signExec)) {
		_signed = true;
	} else {
		throw GradeTooLowException();
	}
}

std::ostream& operator<<(std::ostream& os, const AForm& b) {
	os << "Name: " << b.getName() << " isSigned: " << b.getSigned() << " SignGrade: " << b.getGrade() << " ExecuteGrade: " << b.getExec() << std::endl;
	return (os);
}


AForm::~AForm() {}
