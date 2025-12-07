/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:13:54 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/27 09:13:54 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
	try {
		std::cout << "--- Basic Test ---" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		std::cout << "\n--- Exception Test: Add Too Many ---" << std::endl;
		try {
			sp.addNumber(42);
		} catch (const std::exception& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}

		std::cout << "\n--- Exception Test: Not Enough Numbers ---" << std::endl;
		Span sp2(2);
		sp2.addNumber(1);
		try {
			std::cout << sp2.shortestSpan() << std::endl;
		} catch (const std::exception& e) {
			std::cout << "Caught exception: " << e.what() << std::endl;
		}

		std::cout << "\n--- Copy Constructor Test ---" << std::endl;
		Span spCopy(sp);
		std::cout << "Copy shortest span: " << spCopy.shortestSpan() << std::endl;
		std::cout << "Copy longest span: " << spCopy.longestSpan() << std::endl;

		std::cout << "\n--- Assignment Operator Test ---" << std::endl;
		Span spAssign(10);
		spAssign = sp;
		std::cout << "Assign shortest span: " << spAssign.shortestSpan() << std::endl;
		std::cout << "Assign longest span: " << spAssign.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cout << "Fatal exception: " << e.what() << std::endl;
	}
	return 0;
}
