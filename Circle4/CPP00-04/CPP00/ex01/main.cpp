/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:16:06 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 22:16:06 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phonebook;
	std::string input;

	std::cout << std::endl;
	std::cout << "📞 Welcome to the PhoneBook 📞" << std::endl;
	std::cout << std::endl;
	std::cout << "available commands: ADD SEARCH EXIT" << std::endl;
	while (1)
	{
		std::cout << "Enter command: ";
		getline(std::cin, input);
		if (input == "ADD")
			phonebook.AddContact();
		else if (input == "SEARCH")
			phonebook.SearchContact();
		else if (input == "EXIT")
			break;
	}
	return 0;
}
