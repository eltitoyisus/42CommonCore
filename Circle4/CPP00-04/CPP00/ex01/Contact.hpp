/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:15:54 by jramos-a          #+#    #+#             */
/*   Updated: 2025/05/20 22:15:54 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);

		void set_index(int index);
		void set_firstname(std::string firstname);
		void set_lastname(std::string lastname);
		void set_nickname(std::string nickname);
		bool set_phoneNumber(std::string phoneNumber);
		void set_darkestSecret(std::string darkestSecret);

		int get_index(void) const;
		std::string get_firstname(void) const;
		std::string get_lastname(void) const;
		std::string get_nickname(void) const;
		std::string get_phoneNumber(void) const;
		std::string get_darkestSecret(void) const;

	private:
		std::string _firstname;
		std::string _lastname;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		int _index;
};
