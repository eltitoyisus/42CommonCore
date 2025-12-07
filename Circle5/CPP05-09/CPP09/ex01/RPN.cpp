/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:23:38 by jramos-a          #+#    #+#             */
/*   Updated: 2025/09/24 10:23:38 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &input) {
	parseInput(input);
}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN &RPN::operator=(const RPN &src) {
	if (this != &src) {
	}
	return *this;
}

RPN::~RPN() {}

std::string RPN::parseInput(const std::string &input) {
	std::stringstream ss(input);
	std::string operand;

	while (ss >> operand) {
		if ((operand.size() == 1 && isdigit(operand[0])) ||
		    ((operand[0] == '+' || operand[0] == '-') && operand.size() > 1 && isdigit(operand[1]))) {
			std::stringstream numStream(operand);
			int num;
			numStream >> num;
			
			if (num >= 10)
				throw std::runtime_error("Error: Positive number must be less than 10");
			
			stack.push(num);
		} else if (operand == "+" || operand == "-" || operand == "*" || operand == "/") {
			if (stack.size() < 2)
				throw std::runtime_error("Error: Invalid expression");
			char op = operand[0];
			switch (op) {
			case '+':
				_execStack(&RPN::_plus);
				break;
			case '-':
				_execStack(&RPN::_minus);
				break;
			case '*':
				_execStack(&RPN::_mult);
				break;
			case '/':
				_execStack(&RPN::_div);
				break;
			default:
				throw std::runtime_error("Error: Invalid operator");
			}
		} else {
			throw std::runtime_error("Error: Invalid character");
		}
	}
	return "";
}

double RPN::calculus() const {
	if (stack.size() != 1)
		throw std::runtime_error("Error: Invalid expression");
	return stack.top();
}

void RPN::_execStack(double (RPN::*f)(double, double)) {
	double b = stack.top();
	stack.pop();
	double a = stack.top();
	stack.pop();
	double result = (this->*f)(a, b);
	stack.push(result);
}

double RPN::_plus(double a, double b) {
	return a + b;
}

double RPN::_minus(double a, double b) {
	return a - b;
}

double RPN::_div(double a, double b) {
	if (b == 0)
		throw divisionByZero();
	return a / b;
}

double RPN::_mult(double a, double b) {
	return a * b;
}

const char *RPNException::what() const throw() {
	return ("RPN base error");
}

const char *invalidArgument::what() const throw() {
	return ("Error: Invalid argument");
}

const char *emptyStack::what() const throw() {
	return ("Error: Empty stack");
}

const char *divisionByZero::what() const throw() {
	return ("Error: Division by zero");
}
