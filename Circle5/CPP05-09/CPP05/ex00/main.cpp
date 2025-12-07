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

int main() {
	try {
		Bureaucrat b1("patata", 50);
		std::cout << b1 << std::endl;
		b1.incrementGrade(40);
		std::cout << b1 << std::endl;
		b1.decrementGrade(140);
		std::cout << b1 << std::endl;
		b1.decrementGrade(141);
		std::cout << b1 << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
