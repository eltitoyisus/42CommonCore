/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:50:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/04 11:50:36 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *newz = newZombie("foo");
	Zombie *newz2 = newZombie("patata");

		std::cout << std::endl;

	newz->announce();
	newz2->announce();

		std::cout << std::endl;

	randomChump("Random Zombie");

		std::cout << std::endl;

	delete newz;
	delete newz2;

}
