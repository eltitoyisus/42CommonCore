/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:02:16 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 13:02:16 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_H
# define RB_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	// requires grades sign 72 exec 45
	// makes drilling noises
	// <target> has been robotomized succesfully 50% of the time
	// robotomy failed
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		virtual void execute(Bureaucrat const & executor) const;
		void makeRobot(std::string target);
	private:
		std::string _target;
};

class Robotomy : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif
