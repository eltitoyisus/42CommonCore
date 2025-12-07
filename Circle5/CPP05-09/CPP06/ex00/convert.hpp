/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 08:45:57 by jramos-a          #+#    #+#             */
/*   Updated: 2025/07/23 12:36:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define MAX_FLOAT 3.402823466e+38F
# define MIN_FLOAT -3.402823466e+38F

# define MAX_DOUBLE 1.7976931348623157e+308
# define MIN_DOUBLE -1.7976931348623157e+308

# define MAX_CHAR 126
# define MIN_CHAR 0

#define NAN std::numeric_limits<double>::quiet_NaN()
#define INF std::numeric_limits<double>::infinity()
#define MINF -std::numeric_limits<double>::infinity()

#define NANF std::numeric_limits<float>::quiet_NaN()
#define INFF std::numeric_limits<float>::infinity()
#define MINFF -std::numeric_limits<float>::infinity()

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cstdio>

class ScalarConverter {
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		static void convert(const std::string& input);
		static char toChar(std::string Char);
		static int toInt(std::string Int);
		static float toFloat(std::string Float);
		static double toDouble(std::string Double);
	private:
		
};

#endif
