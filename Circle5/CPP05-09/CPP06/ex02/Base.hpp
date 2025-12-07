/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:17:19 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/28 14:17:19 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

// typeinfo header forbidden
#include <iostream>

class A;
class B;
class C;

class Base {
	public:
		virtual ~Base();

		// randomly instances a,b,c and returns the instance as a Base pointer.
		Base* generate(void);
		// prints the actual type of the object pointed to P by: a,b,c.
		void identify(Base* p);
		// prints the actual type of the object referenced by P: a,b,c (cant use pointer inside)
		void identify(Base& p);
	private:
};

#endif
