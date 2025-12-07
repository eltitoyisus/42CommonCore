/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:02:39 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/17 13:02:39 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PR_H
# define PR_H

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	// sign 25, exec 5
	// informs that <target> has beeen pardoned by Zaphod Beeblebrox
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		virtual void execute(Bureaucrat const & executor) const;
		void pardon(std::string target);
	private:
		std::string _target;
};

#endif
