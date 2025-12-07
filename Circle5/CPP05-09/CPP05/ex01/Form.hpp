/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:16:21 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 10:16:21 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form();
		Form(const std::string name, const int _signGrade, const int _signExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		void beSigned(const Bureaucrat& b);

		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getExec() const;
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _signExec;
};


std::ostream& operator<<(std::ostream& os, const Form& b);

#endif
