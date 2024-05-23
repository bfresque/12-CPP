/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:16 by bfresque          #+#    #+#             */
/*   Updated: 2024/05/23 12:07:07 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN& other) { (void)other; }

RPN& RPN::operator=(const RPN& other) { (void)other; return (*this); }

RPN::RPN::~RPN() { }

double evaluate_rpn(const std::string& expression) {
	std::istringstream iss(expression);
	std::stack<double> stack;
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
			if (token.find('.') != std::string::npos)
				throw std::runtime_error("Error: Decimal numbers are not allowed");
			double number = atof(token.c_str());
			if (number >= 10)
				throw std::runtime_error("Error: Numbers must be less than 10");
			stack.push(number);
		}
		else {
			if (stack.size() < 2)
				throw std::runtime_error("Error: Value in the expression");
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
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: The expression is invalid");
	return (stack.top());
}