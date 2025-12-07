/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:13:56 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/12 14:13:56 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_store_bit = 8;

Fixed::Fixed() : _store_fixed(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
	// std::cout << "Int constructor called" << std::endl;
	_store_fixed = i << _store_bit;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constructor called" << std::endl;
	_store_fixed = roundf(f * (1 << _store_bit));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	_store_fixed = other._store_fixed;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_store_fixed = other._store_fixed;
	}
	return *this;
}

int Fixed::operator>(const Fixed& other) const
{
	return (_store_fixed > other._store_fixed);
}

int Fixed::operator<(const Fixed& other) const
{
	return (_store_fixed < other._store_fixed);
}

int Fixed::operator>=(const Fixed& other) const
{
	return (_store_fixed >= other._store_fixed);
}

int Fixed::operator<=(const Fixed& other) const
{
	return (_store_fixed <= other._store_fixed);
}

int Fixed::operator==(const Fixed& other) const
{
	return (_store_fixed == other._store_fixed);
}

int Fixed::operator!=(const Fixed& other) const
{
	return (_store_fixed != other._store_fixed);
}


Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_store_fixed + other._store_fixed);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(_store_fixed - other._store_fixed);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}


Fixed Fixed::operator++()
{
	_store_fixed += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	_store_fixed += 1;
	return temp;
}

Fixed Fixed::operator--()
{
	_store_fixed -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	_store_fixed -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}



Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return _store_fixed;
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	_store_fixed = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_store_fixed / (1 << _store_bit);
}

int Fixed::toInt(void) const
{
	return _store_fixed >> _store_bit;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return out;
}
