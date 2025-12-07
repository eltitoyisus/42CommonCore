/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:12:56 by jramos-a          #+#    #+#             */
/*   Updated: 2025/08/27 09:12:56 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0), _array(NULL), _current(0) {}

Span::Span(unsigned int N) : _N(N), _current(0) {
	_array = new int[N];
}

Span::Span(const Span &other) : _N(other._N), _current(other._current) {
	_array = new int[_N];
	for (unsigned int i = 0; i < _current; ++i) {
		_array[i] = other._array[i];
	}
}

Span& Span::operator=(const Span &other) {
	if (this != &other) {
		delete[] _array;
		_N = other._N;
		_current = other._current;
		_array = new int[_N];
		for (unsigned int i = 0; i < _current; ++i) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

Span::~Span() {
	delete[] _array;
}

void Span::addNumber(int number) {
	if (_current >= _N)
		throw SpanFullException();
	_array[_current] = number;
	_current++;
}

int Span::shortestSpan() {
	if (_current <= 1)
		throw NoSpanFoundException();
	int *sorted = new int[_current];
	for (unsigned int i = 0; i < _current; i++) {
		sorted[i] = _array[i];
	}
	std::sort(sorted, sorted + _current);
	int minSpan = INT_MAX;
	for (unsigned int i = 0; i < _current - 1; i++) {
		int span = sorted[i + 1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	delete[] sorted;
	return minSpan;
}

int Span::longestSpan() {
	if (_current <= 1)
		throw NoSpanFoundException();
	int *sorted = new int[_current];
	for (unsigned int i = 0; i < _current; i++) {
		sorted[i] = _array[i];
	}
	std::sort(sorted, sorted + _current);
	int result = sorted[_current - 1] - sorted[0];
	delete[] sorted;
	return result;
}


const char* SpanFullException::what() const throw() {
	return "Span is full";
}

const char* NoSpanFoundException::what() const throw() {
	return "Span can't be found";
}