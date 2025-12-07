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
	Zombie *horde;
	int N = 5;
	std::string name = "test";

	horde = zombieHorde(N, name);
	std::cout << std::endl;
	for (int i = 0; i < N; i++)
	{
		horde[i].announce(i, name);
	}
	std::cout << std::endl;
	delete[] horde;
}
