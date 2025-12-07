/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:49:05 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/14 19:49:05 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include "Animal.hpp"
#include <string>

class Brain {
	public:
		// array of 100 std::String "ideas" 

		// dogs and cat have a private *Brain atrribute
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdeas(std::string idea);
		void getIdeas();

	protected:
		std::string _ideas[100];
		// upcon creation crete a newBrain()
		// upon destruction destory newBrain()
};

#endif
