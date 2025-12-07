/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:16:16 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 22:16:16 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void) : _index(0)
{
	// std::cout << "PhoneBook constructor called" << std::endl;
}

void PhoneBook::AddContact(void)
{
	Contact newContact;
	std::string input;

	while (true)
	{
		std::cout << "Enter first name: ";
		std::getline(std::cin, input);
		if (!input.empty())
		{
			newContact.set_firstname(input);
			break;
		}
		std::cout << "Field cannot be empty" << std::endl;
	}

	while (true)
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (!input.empty())
		{
			newContact.set_lastname(input);
			break;
		}
		std::cout << "Field cannot be empty" << std::endl;
	}

	while (true)
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (!input.empty())
		{
			newContact.set_nickname(input);
			break;
		}
		std::cout << "Field cannot be empty" << std::endl;
	}

	while (true)
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (!input.empty() && newContact.set_phoneNumber(input))
			break;
		std::cout << "Invalid phone number" << std::endl;
	}

	while (true)
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (!input.empty())
		{
			newContact.set_darkestSecret(input);
			break;
		}
		std::cout << "Field cannot be empty" << std::endl;
	}

	if (this->_index > 7)
		this->_contacts[7] = newContact;

	else
	{
	this->_contacts[this->_index % 8] = newContact;
	this->_index++;
	}
}


void truncate_contact(std::string str)
{
	if (str.length() < 10)
	{
		int n = 10 - str.length();
		for (int i = 0; i <= n; i++)
			std::cout << " ";
	}
	else if (str.length() > 10)
	{
		std::cout << " ";
		str = str.substr(0, 9) + ".";
	}
	std::cout << str;
}

void PhoneBook::SearchContact(void)
{
	std::string input;

	std::cout << "     Index | First Name | Last Name  |  Nickname  |" << std::endl;
	for (int i = 0; i < this->_index && i < 8; i++)
	{
		std::cout << std::setw(10) << i << " |";
		truncate_contact(this->_contacts[i].get_firstname());
		std::cout << " |";
		truncate_contact(this->_contacts[i].get_lastname());
		std::cout << " |";
		truncate_contact(this->_contacts[i].get_nickname());
		std::cout << " |";
		std::cout << std::endl;
	}
	std::cout << "Select index to search: ";
	std::getline(std::cin, input);
	if (input.empty() || !std::isdigit(static_cast<unsigned char>(input[0])))
	{
		std::cout << "Error: Invalid input" << std::endl;
		return;
	}
	int i = input[0] - '0';
	if (i < this->_index && i < 8)
	{
		std::cout << std::setw(10) << input << " |";
		truncate_contact(this->_contacts[i].get_firstname());
		std::cout << " |";
		truncate_contact(this->_contacts[i].get_lastname());
		std::cout << " |";
		truncate_contact(this->_contacts[i].get_nickname());
		std::cout << " |";
		std::cout << std::endl;
	}
	else
		std::cout << "Error: Index out of range" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "PhoneBook destructor called" << std::endl;
}
