/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:42:19 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/23 12:42:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>

class Serializer {
	public:
		// You must create a non-empty (meaning it has data members) Data structure.

		// Use serialize() on the address of the Data object and pass its return value to
		//deserialize(). Then, ensure the return value of deserialize() compares equal to the
		//original pointer.

		// takes a pointer and converts it  to uintptr_t
		static uintptr_t serialize(Data* ptr);
		// takes a uintptr_t and converts it to a pointer to Data
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();
};

#endif
