/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:31:33 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/24 11:31:33 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
		return 1;
	}
	PmergeMe pmergeMe;
	pmergeMe.insertValues(argv + 1, argc - 1);
	pmergeMe.sortAndDisplay();
	return 0;
}
