/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:26:16 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:26:16 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void Iter(T* arr, int len, F func) {
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void printArr(const T& i) {
	std::cout << "[" << i << "] " << "patata" << std::endl;
}

#endif
