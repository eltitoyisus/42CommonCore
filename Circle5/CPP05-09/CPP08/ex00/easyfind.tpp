/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:03:00 by jramos-a          #+#    #+#             */
/*   Updated: 2025/10/31 11:03:00 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyFind(const T& container, int i) {
	typename T::const_iterator it = std::find(container.begin(), container.end(), i);
	// find first occurence of the second paramater in the first paramater
	if (it == container.end()) {
			throw ValueNotFoundException();
	}
	// if no occourrence is found throw exceptiion with a value
	return it;
}

const char* ValueNotFoundException::what() const throw() {
	return "Value not found";
}
