/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:13:50 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/12 14:13:50 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>


class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		// COMPARISON
		int operator>(const Fixed& other) const;
		int operator>=(const Fixed& other) const;
		int operator<(const Fixed& other) const;
		int operator<=(const Fixed& other) const;
		int operator==(const Fixed& other) const;
		int operator!=(const Fixed& other) const;
		

		// ARITHMETIC
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;


		// INCREMENT - DECREMENT
		Fixed operator++();
		Fixed operator++(int);
		Fixed operator--();
		Fixed operator--(int);


		// OVERLOAD MEMBERS
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int _store_fixed;
		static const int _store_bit;
	};

	std::ostream& operator<<(std::ostream& out, const Fixed& value);

	#endif
