/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:46:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/31 23:46:57 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
	public:
		// empty array
		Array();
		// array of n element
		Array(unsigned int n);
		// it musnt affect the array
		Array(const Array& other);
		// it musnt modify the array
		Array& operator=(const Array& other);
		~Array();
		// member function size returns number of elements on the array.
		// takes no params and doesnt modify
		T& operator[](unsigned int idx);
		const T& operator[](unsigned int idx) const;
		unsigned int size() const;
	private:
		T* _arr;
		unsigned int _size;
};

#include "Array.tpp"

#endif
