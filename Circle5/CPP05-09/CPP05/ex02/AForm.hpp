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

#ifndef AFORM_H
# define AFORM_H

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm();
		AForm(const std::string name, const int _signGrade, const int _signExec);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		void beSigned(const Bureaucrat& b);

		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;
		int getExec() const;

		virtual void execute(Bureaucrat const & executor) const = 0;
	private:
		const std::string _name;
		bool _signed;
		const int _signGrade;
		const int _signExec;
};


std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif
