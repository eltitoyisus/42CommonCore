/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 09:13:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/16 14:09:08 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria* _inventory[4];
		int _count;

	public:
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
