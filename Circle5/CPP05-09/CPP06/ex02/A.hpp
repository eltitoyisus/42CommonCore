/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:25:19 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/28 14:25:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

#include <iostream>
#include "Base.hpp"

class A : public Base {
	public:
		A();
		virtual ~A();

		void identify() const;
};

#endif
