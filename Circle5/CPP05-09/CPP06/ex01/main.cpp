/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:41:55 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/23 12:41:55 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
	Data original;
	original.id = 42;
	original.name = "Test";

	uintptr_t raw = Serializer::serialize(&original);
	std::cout << "Serialized uintptr_t: " << raw << std::endl;

	Data* reconstructed = Serializer::deserialize(raw);

	if (reconstructed == &original) {
		std::cout << "Pointers match! ✅" << std::endl;
		std::cout << "Reconstructed Data -> id: " << reconstructed->id
					<< ", name: " << reconstructed->name << std::endl;
	} else {
		std::cout << "Pointers do NOT match ❌" << std::endl;
	}

	return 0;
}
