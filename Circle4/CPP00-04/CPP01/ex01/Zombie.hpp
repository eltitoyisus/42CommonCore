/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 11:52:18 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/04 11:52:18 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <new>

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();

		void announce(int i, std::string name);

	private:
		std::string _name;
};
		Zombie* zombieHorde(int N, std::string name);
