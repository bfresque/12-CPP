/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:16 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/27 10:49:00 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN& other) { (void)other; }

RPN& RPN::operator=(const RPN& other) { (void)other; return (*this); }

RPN::~RPN() { }

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cmath>

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cctype>
#include <cmath>

// jai lair de bien bloque les nombres negatif mais il y a un probleme de coherence je bloque +0 cest bien mais je bloque pas -0 il faut qussi que cel soit bloque
double RPN::evaluate_rpn(const std::string& expression) {
	std::istringstream iss(expression);
	std::stack<double> stack;
	std::string token;
	int operatorCount = 0;
	int numberCount = 0;

	while (iss >> token) {
		bool isNumber = true;
		for (size_t i = 0; i < token.size(); ++i) {
			if (!isdigit(token[i]) && !(i == 0 && token[i] == '-' && token.size() > 1)) {
				isNumber = false;
				break;
			}
		}

		if (isNumber) {
			if (token.find('.') != std::string::npos)
				throw std::runtime_error("Error: Decimal numbers are not allowed");
			double number = atof(token.c_str());
			if (std::signbit(number) && number == 0.0)
				throw std::runtime_error("Error: -0 is not allowed");
			if (number < 0 || number >= 10)
				throw std::runtime_error("Error: Numbers must be positive and less than 10");
			stack.push(number);
			numberCount++;
		}
		else {
			if (token.size() != 1 || (token[0] != '+' && token[0] != '-' && token[0] != '*' && token[0] != '/'))
				throw std::runtime_error("Error: Invalid token");
			if (stack.size() < 2)
				throw std::runtime_error("Error: Insufficient values in the expression");

			double second = stack.top();
			stack.pop();
			double first = stack.top();
			stack.pop();

			double result;
			switch (token[0]) {
				case '+':
					result = first + second;
					break;
				case '-':
					result = first - second;
					break;
				case '*':
					result = first * second;
					break;
				case '/':
					if (second == 0)
						throw std::runtime_error("Error: Division by zero");
					result = first / second;
					result = (result > 0) ? std::floor(result) : std::ceil(result);
					break;
				default:
					throw std::runtime_error("Error: Unknown operator");
			}
			stack.push(result);
			operatorCount++;
		}
	}
	if (stack.size() != 1 || numberCount <= operatorCount)
		throw std::runtime_error("Error: The expression is invalid");
	return (stack.top());
}