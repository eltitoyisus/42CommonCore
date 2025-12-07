/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 09:49:20 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/24 09:49:20 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>

// number number operand = number operand number
// 5 6 + = 5 + 6        3 2 * 5 + = 3 * 2 + 5

// push to stack 2 numbers and operand, then calculate | after continue pushing to operand and calculate

class RPN {
	public:
		RPN();
		RPN(const std::string &input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		std::string parseInput(const std::string &input);
		double calculus() const;
		// numbers < 10
		// msgs of error in stderror
		// handle +-/*
	private:
		std::stack<double> stack;
		void _execStack(double (RPN::*f)(double, double));
		double _plus(double a, double b);
		double _minus(double a, double b);
		double _div(double a, double b);
		double _mult(double a, double b);
};

// exception classes
class RPNException : public std::exception {
 	public:
 		virtual const char* what() const throw();
};

class invalidArgument : public RPNException {
 	public:
 		virtual const char* what() const throw();
};

class emptyStack : public RPNException {
 	public:
 		virtual const char* what() const throw();
};

class divisionByZero : public RPNException {
 	public:
 		virtual const char* what() const throw();
};

#endif