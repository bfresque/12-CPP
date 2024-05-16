/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:24:16 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/26 12:27:21 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

double evaluate_rpn(const std::string& expression) {
	std::istringstream iss(expression);
	std::stack<double> stack;
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
			stack.push(atof(token.c_str()));
		else {
			if (stack.size() < 2)
				throw std::runtime_error("Error");
			double second = stack.top();
			stack.pop();
			double first = stack.top();
			stack.pop();

			switch (token[0]) {
				case '+':
					stack.push(first + second);
					break;
				case '-':
					stack.push(first - second);
					break;
				case '*':
					stack.push(first * second);
					break;
				case '/':
					if (second == 0)
						throw std::runtime_error("Division by zero");
					stack.push(first / second);
					break;
				default:
					throw std::runtime_error("Error");
			}
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error");
	return (stack.top());
}