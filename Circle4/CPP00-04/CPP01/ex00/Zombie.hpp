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
		Zombie(std::string name);
		~Zombie();

		void announce(void);

	private:
		std::string _name;
};

		Zombie* newZombie(std::string name);
		void randomChump(std::string name);
