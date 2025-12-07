/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:28:51 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/28 14:28:51 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base::~Base() {}

Base* Base::generate(void) {
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

void Base::identify(Base* p) {
	try {
		(void)dynamic_cast<A&>(*p);
		std::cout << "I am class A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(*p);
		std::cout << "I am class B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(*p);
		std::cout << "I am class C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown type" << std::endl;
}

void Base::identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "I am class A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "I am class B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "I am class C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "Unknown type" << std::endl;
}
