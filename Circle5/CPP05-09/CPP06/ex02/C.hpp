/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:27:49 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/28 14:27:49 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

#include <iostream>
#include "Base.hpp"

class C : public Base {
	public:
		C();
		virtual ~C();

		void identify() const;
};

#endif
