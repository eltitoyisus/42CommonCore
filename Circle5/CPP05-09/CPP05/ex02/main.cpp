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

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// constructor of forms only 1 parameter
// implement the exec function in the propper classes
// check if the form is signed and the bureaucrat grade

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
		try {
			Bureaucrat b1("Alice", 5);
			Bureaucrat b2("Bob", 45);
			Bureaucrat b3("Charlie", 137);

			ShrubberyCreationForm shrub("Home");
			PresidentialPardonForm pardon("Criminal");
			RobotomyRequestForm robot("Bender");

			std::cout << "\n==============================" << std::endl;
			std::cout << "Bureaucrats:" << std::endl;
			std::cout << b1 << std::endl;
			std::cout << b2 << std::endl;
			std::cout << b3 << std::endl;
			std::cout << "==============================\n" << std::endl;

			std::cout << "Forms:" << std::endl;
			std::cout << shrub << std::endl;
			std::cout << pardon << std::endl;
			std::cout << robot << std::endl;
			std::cout << "==============================\n" << std::endl;

			Bureaucrat* bureaucrats[3] = {&b3, &b2, &b1};
			AForm* forms[3] = {&shrub, &robot, &pardon};
			std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

			for (int i = 0; i < 3; ++i) {
				std::cout << "\n--- " << bureaucrats[i]->getName() << " attempts to sign and execute " << formNames[i] << " ---" << std::endl;
				bureaucrats[i]->signAForm(*forms[i]);
				bureaucrats[i]->executeForm(*forms[i]);
			}

		} catch (std::exception &e) {
			std::cerr << "\n[ERROR] Exception caught: " << e.what() << std::endl;
		}

		std::cout << "\nProgram finished.\n" << std::endl;
		return 0;
}
