/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:33:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/16 23:33:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		//rank form 1 (highest) to 150 (lowest)
		int _grade;
		const std::string _name;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		//exceptions for too low and too high grades
		// overload intersection << "<name>, bureaucrat grade <grade>"

		std::string getName() const;
		int getGrade() const;
		// if it goes out of range bowth show same exception as the constrcutor
		void incrementGrade(int inc);
		void decrementGrade(int dec);
		void signAForm(Form &form);
};

class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
