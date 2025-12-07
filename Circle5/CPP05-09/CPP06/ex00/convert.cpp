/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:30:14 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/22 14:30:14 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string& input) {
	std::cout << "Converting: " << input << std::endl << std::endl;
	toChar(input);
	toInt(input);
	toFloat(input);
	toDouble(input);
}

ScalarConverter::~ScalarConverter() {}

// make a rule for nan and nanf
// pass only displayable characters
char ScalarConverter::toChar(std::string Char) {
	if (Char.length() == 1 && std::isprint(Char[0]) && !std::isdigit(Char[0])) {
		std::cout << "char: '" << Char[0] << "'" << std::endl;
		return Char[0];
	}
	if (Char == "nan" || Char == "nanf" || Char == "inf" ||
		Char == "inff" || Char == "-inf" || Char == "-inff" ||
		Char == "+inf" || Char == "+inff") {
		std::cerr << "char: impossible" << std::endl;
		return 0;
	}

	int value;
	std::stringstream ss(Char);
	ss >> value;
	if (!ss.fail() && ss.eof()) {
		if (value < MIN_CHAR || value > MAX_CHAR) {
			std::cerr << "char: Non displayable" << std::endl;
			return 0;
		}
		if (!std::isprint(value)) {
			std::cerr << "char: Non displayable" << std::endl;
			return 0;
		}
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
		return static_cast<char>(value);
	}

	double dvalue;
	std::stringstream ss2(Char);
	ss2 >> dvalue;
	if (!ss2.fail() && (ss2.peek() == 'f' || ss2.peek() == EOF)) {
		if (dvalue < MIN_CHAR || dvalue > MAX_CHAR || dvalue != static_cast<int>(dvalue)) {
			std::cerr << "char: impossible" << std::endl;
			return 0;
		}
		if (!std::isprint(static_cast<int>(dvalue))) {
			std::cerr << "char: Non displayable" << std::endl;
			return 0;
		}
		std::cout << "char: '" << static_cast<char>(static_cast<int>(dvalue)) << "'" << std::endl;
		return static_cast<char>(static_cast<int>(dvalue));
	}
	std::cerr << "char: impossible" << std::endl;
	return 0;
}

// int literal
int ScalarConverter::toInt(std::string Int) {
	std::stringstream ss(Int);
	int i = 0;
	ss >> i;
	if (ss.fail() || ss.bad() || Int == "nan" || Int == "nanf" || Int == "inf" ||
		Int == "inff" || Int == "-inf" || Int == "-inff") {
		std::cerr << "int: impossible" << std::endl;
		return 0;
	}
	std::cout << "int: " << i << std::endl;
	return i;
}

// pseudo litarals nanf, -inff, +inff
float ScalarConverter::toFloat(std::string Float) {
	if (Float == "nan" || Float == "nanf") {
		std::cout << "float: nanf" << std::endl;
		return NANF;
	}
	if (Float == "+inf" || Float == "+inff" || Float == "inf" || Float == "inff") {
		std::cout << "float: +inff" << std::endl;
		return INFF;
	}
	if (Float == "-inf" || Float == "-inff") {
		std::cout << "float: -inff" << std::endl;
		return MINFF;
	}
	std::stringstream ss(Float);
	float f = 0.0f;
	ss >> f;
	if (ss.fail() || ss.bad()) {
		std::cerr << "float: impossible" << std::endl;
		return 0.0f;
	}
	std::cout << "float: " << f;
	if (f == static_cast<int>(f))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	return f;
}

// pseudolierals nan, -inf, +inf
double ScalarConverter::toDouble(std::string Double) {
	if (Double == "nan" || Double == "nanf") {
		std::cout << "double: nan" << std::endl;
		return NAN;
	}
	if (Double == "+inf" || Double == "+inff" || Double == "inf" || Double == "inff") {
		std::cout << "double: +inf" << std::endl;
		return INF;
	}
	if (Double == "-inf" || Double == "-inff") {
		std::cout << "double: -inf" << std::endl;
		return MINF;
	}
	std::stringstream ss(Double);
	double d = 0.0;
	ss >> d;
	if (ss.fail() || ss.bad()) {
		std::cerr << "double: impossible" << std::endl;
		return 0.0;
	}
	std::cout << "double: " << d;
	if (d == static_cast<int>(d))
		std::cout << ".0";
	std::cout << std::endl;
	return d;
}
