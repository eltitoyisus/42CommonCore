/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 09:22:13 by jramos-a          #+#    #+#             */
/*   Updated: 2025/06/26 09:22:13 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed
{
	public:
		Fixed(); // default constructor, init value to 0
		Fixed(const Fixed &other);// cpy constructor
		Fixed& operator=(const Fixed& other); // cpy assingment operator overload
		~Fixed(); // destructor
		int getRawBits( void ) const; // member function returns raw value of fixed-point
		void setRawBits( int const raw ); // member function sets raw value of fixed-point

	private:
		int _store_fixed; // this is to store the fixed-point number value
		static const int _store_bit; // stores the numbers of fractional bits, the value will always be the integer literal 8
};
