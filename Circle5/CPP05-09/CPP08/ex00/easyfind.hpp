/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:30:56 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/12 09:30:56 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>

class ValueNotFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
};

// T is a container of integers
template <typename T>
typename T::const_iterator easyFind(const T& container, int i);

#include "easyfind.tpp"

#endif
