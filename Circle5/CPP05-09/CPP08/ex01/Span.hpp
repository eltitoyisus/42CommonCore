/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:13:09 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/27 09:13:09 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <climits>
#include <cstdlib>

class Span {
	public:
	// can store maximum of N integers
	// N is used as unsgined int only parameter passed to constructor
		Span();
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();
	//member function called addNumber() to add single number to span
		void addNumber(int number);
	// if already N element throw exception

	// shortestSpan() longestSpan()
		int shortestSpan();
		int longestSpan();
	// if no nombers ot 1, no span can be found

	// span at least 10000 numbers
	private:
		unsigned int _N;
		int *_array;
		unsigned int _current;
};	

class SpanFullException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class NoSpanFoundException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif