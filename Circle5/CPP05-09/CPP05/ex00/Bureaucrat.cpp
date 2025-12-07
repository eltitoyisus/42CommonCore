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

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
	if (grade < 1)
		throw std::out_of_range("Grade Too High Exception");
	if (grade > 150)
		throw std::out_of_range("Grade Too Low Exception");
	_grade = grade;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade(int inc) {
	if (_grade - inc < 1)
		throw std::out_of_range("Grade Too High Exception");
	_grade -= inc;
}

void Bureaucrat::decrementGrade(int dec) {
	if (_grade + dec > 150)
		throw std::out_of_range("Grade Too Low Exception");
	_grade += dec;
}

const char* GradeTooLowException::what() const throw() {
	return "Grade Too Low Exception";
}

const char* GradeTooHighException::what() const throw() {
	return "Grade Too High Exception";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat() {}
