/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:27:11 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/28 14:27:11 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

#include <iostream>
#include "Base.hpp"

class B : public Base {
	public:
		B();
		virtual ~B();

		void identify() const;
};

#endif
