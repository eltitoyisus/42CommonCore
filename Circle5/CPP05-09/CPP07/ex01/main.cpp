/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:25:46 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:25:46 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	int len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Testing with an int array: ";
	std::cout << std::endl;
	Iter(arr, len, printArr<int>);
	std::cout << std::endl;

	double arrD[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	int lenD = sizeof(arrD) / sizeof(arrD[0]);

	std::cout << "Testing with a double array: ";
	std::cout << std::endl;
	Iter(arrD, lenD, printArr<double>);
	std::cout << std::endl;

	std::string arrS[] = {"Porsche", "Aston Martin", "Ferrari"};
	int lenS = sizeof(arrS) / sizeof(arrS[0]);

	std::cout << "Testing with a string array: ";
	std::cout << std::endl;
	Iter(arrS, lenS, printArr<std::string>);
	std::cout << std::endl;
}
