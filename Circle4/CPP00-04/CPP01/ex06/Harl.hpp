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
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);
};

void complain( std::string level );
