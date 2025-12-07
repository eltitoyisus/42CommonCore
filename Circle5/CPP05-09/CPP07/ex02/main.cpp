/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:50:10 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/31 23:50:10 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// use new[] to allocate memory| must never access non-allocated memory
// elements can be accessed by []

// if accessing with [] and is out of bounds std::Exception (std::out_of_range)

int main() {
	Array<int> arr(5);
	for (int i = 0; i < 5; i++) {
		arr[i] = i * 10;
	}

	Array<int> arrCopy(arr);
	Array<int> arrAssign;
	arrAssign = arr;

	std::cout << "Original Array: ";
	for (unsigned int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Copied Array: ";
	for (unsigned int i = 0; i < arrCopy.size(); i++) {
		std::cout << arrCopy[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Assigned Array: ";
	for (unsigned int i = 0; i < arrAssign.size(); i++) {
		std::cout << arrAssign[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
