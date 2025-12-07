/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:35:19 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/16 23:35:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	Intern someRandomIntern;
	Bureaucrat boss("Alice", 1);
	Bureaucrat worker("Bob", 50);

	std::cout << "\n--- Intern creates forms ---\n";
	AForm* shrubbery = someRandomIntern.makeForm("shrubbery creation", "Garden");
	AForm* robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Charlie");
	AForm* unknown = someRandomIntern.makeForm("unknown form", "Nobody");

	std::cout << "\n--- Bureaucrat signs and executes forms ---\n";
	if (shrubbery) {
		boss.signAForm(*shrubbery);
		try {
			boss.executeForm(*shrubbery);
		} catch (const std::exception& e) {
			std::cerr << "Error executing ShrubberyCreationForm: " << e.what() << std::endl;
		}
		delete shrubbery;
	}
	if (robotomy) {
		worker.signAForm(*robotomy);
		try {
			worker.executeForm(*robotomy);
		} catch (const std::exception& e) {
			std::cerr << "Error executing RobotomyRequestForm: " << e.what() << std::endl;
		}
		delete robotomy;
	}
	if (pardon) {
		boss.signAForm(*pardon);
		try {
			boss.executeForm(*pardon);
		} catch (const std::exception& e) {
			std::cerr << "Error executing PresidentialPardonForm: " << e.what() << std::endl;
		}
		delete pardon;
	}
	if (!unknown) {
		std::cout << "Intern could not create 'unknown form'.\n";
	}
}
