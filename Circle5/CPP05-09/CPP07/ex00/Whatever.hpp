/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:03:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/30 14:03:57 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swapV(T &v1, T &v2) {
	T temp = v1;
	v1 = v2;
	v2 = temp;
}

template <typename T>
T minV(const T &v1, const T &v2) {
	return (v1 < v2 ? v1 : v2);
}

template <typename T>
T maxV(const T &v1, const T &v2) {
	return (v1 > v2 ? v1 : v2);
}

#endif