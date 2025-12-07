/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 13:44:19 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/24 13:44:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void complain( std::string level );

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

void complain( std::string level );
