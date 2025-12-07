/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:46:58 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/24 12:46:58 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int argc, char **argv)
{
	if (argc == 4)
		replace_file(argv[1], argv[2], argv[3]);
	else
	{
		std::cout << "Invalid arg number" << std::endl;
		std::cout << "USAGE: <filename> <s1 to search> <s2 to replace>" << std::endl;
	}
}
