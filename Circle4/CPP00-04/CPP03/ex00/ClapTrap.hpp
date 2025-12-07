/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 05:35:26 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 05:35:26 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		//getters and setters
		std::string getName() const;
		void setAttackDamage(unsigned int damage);
		unsigned int getAttackDamage();
	private:
		std::string _name; // passed in the constturctor
		unsigned int _hitPoints; // init to 10 (health points)
		unsigned int _energyPoints; // init to 10
		unsigned int _attackDamage; // init to 0
};
