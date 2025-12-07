/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:51:41 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 15:51:41 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER 10

// int main() {
// 	// create an array filled with 50% cat and 50% dogs
// 	// at the end, delete all
// 	// delete them as animals

// 	const Animal* animals[NUMBER];

// 	for(int i = 0; i < NUMBER; i++) {
// 		if ((i % 2) == 0)
// 			animals[i] = new Dog();
// 		else
// 			animals[i] = new Cat();
// 	}

// 	for (int k = 0; k < NUMBER; k++) {
// 		std::cout << "[" << k << "] ";
// 		animals[k]->makeSound();
// 	}

// 	for (int j = (NUMBER -1); j >= 0; j--) {
// 		delete animals[j];
// 	}

// 	return 0;
// }

// IDEA USE
int main() {
	// create an array filled with 50% cat and 50% dogs
	// at the end, delete all
	// delete them as animals

	Dog* dog = new Dog();
	Cat* cat = new Cat();

	// this cant be used due being a pure virtual method
	// const Animal* mein = new Animal();

	dog->setIdeas("Follow that bird!!");
	cat->setIdeas("I want fish!!");

	std::cout << "[" << "Dog" << "] ";
	dog->getIdea();

	std::cout << "[" << "Cat" << "] ";
	cat->getIdea();

	delete dog;
	delete cat;

	return 0;
}
