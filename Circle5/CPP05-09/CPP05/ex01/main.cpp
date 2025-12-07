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
#include "Form.hpp"

int main() {
	try {
		Bureaucrat b1("<patata>", 50);
		Form f1("<Tratado de Versalles>", 35, 40);
		b1.signAForm(f1);
		b1.incrementGrade(15);
		std::cout  << b1 << std::endl;
		b1.signAForm(f1);
		std::cout << f1 << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
