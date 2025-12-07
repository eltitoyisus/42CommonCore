/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:46:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/10/30 13:48:14 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	_size = 0;
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(unsigned int n) {
	_size = n;
	_arr = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& other) {
	_size = other._size;
	_arr = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		_arr[i] = other._arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _arr;
		_size = other._size;
		_arr = new T[_size];
		for (unsigned int i = 0; i < _size; i++) {
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx) {
	if (idx >= _size)
		throw std::out_of_range("Index out of bounds");
	return _arr[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const {
	if (idx >= _size)
		throw std::out_of_range("Index out of bounds");
	return _arr[idx];
}

template <typename T>
unsigned int Array<T>::size() const {
	return _size;
}

#endif