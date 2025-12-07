/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:39:35 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 21:39:35 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	// std::cout << "Contact constructor called" << std::endl;
}

// Setters for Contact class

void Contact::set_index(int index)
{
	this->_index = index;
}

void Contact::set_firstname(std::string firstname)
{
	this->_firstname = firstname;
}

void Contact::set_lastname(std::string lastname)
{
	this->_lastname = lastname;
}

void Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

bool Contact::set_phoneNumber(std::string phoneNumber)
{
			if (phoneNumber.empty())
				return false;
			int n = phoneNumber.length();
			for (int i = 0; i < n; i++)
			{
				if (!std::isdigit(static_cast<unsigned char>(phoneNumber[i])))
					return false;
			}
			this->_phoneNumber = phoneNumber;
			return true;
}

void Contact::set_darkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}



// Getters for Contact class

int Contact::get_index(void) const
{
	return this->_index;
}

std::string Contact::get_firstname(void) const
{
	return this->_firstname;
}

std::string Contact::get_lastname(void) const
{
	return this->_lastname;
}

std::string Contact::get_nickname(void) const
{
	return this->_nickname;
}

std::string Contact::get_phoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::get_darkestSecret(void) const
{
	return this->_darkestSecret;
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructor called" << std::endl;
}
