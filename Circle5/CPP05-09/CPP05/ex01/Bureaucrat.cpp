/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:35:00 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/16 23:35:00 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// watch try catch exceptions

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade(int inc) {
	if (_grade - inc < 1)
		throw GradeTooHighException();
	_grade -= inc;
}

void Bureaucrat::decrementGrade(int dec) {
	if (_grade + dec > 150)
		throw GradeTooLowException();
	_grade += dec;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

const char *GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

void Bureaucrat::signAForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

Bureaucrat::~Bureaucrat() {}
