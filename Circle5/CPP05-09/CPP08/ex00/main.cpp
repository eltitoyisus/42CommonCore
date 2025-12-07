/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:31:00 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/12 09:31:00 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

// int main() {
// 	std::vector<int> vec = {10, 20, 30, 40, 50};
// 	std::list<int> lst = {5, 15, 25, 35, 45};

// 	std::vector<int>::iterator it = easyFind(vec, 30);
// 	std::cout << *it << std::endl;

// 	std::list<int>::iterator it = easyFind(lst, 30);
// 	std::cout << *it << std::endl;
// }

int main() {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(15);
	lst.push_back(25);
	lst.push_back(35);
	lst.push_back(45);

	try {
		std::vector<int>::const_iterator itVec = easyFind(vec, 30);
		std::cout << *itVec << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::list<int>::const_iterator itLst = easyFind(lst, 30);
		std::cout << *itLst << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
