/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:31:59 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/28 14:31:59 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

int main() {
	srand(static_cast<unsigned int>(std::time(0)));
	Base base;
	Base* instance = base.generate();

	std::cout << "Identifying using pointer:" << std::endl;
	base.identify(instance);

	std::cout << "Identifying using reference:" << std::endl;
	base.identify(*instance);

	delete instance;
	return 0;
}
