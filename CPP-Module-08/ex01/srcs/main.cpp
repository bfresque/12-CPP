/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/16 16:47:33 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

int main() {
	try {
		std::cout << BLUE << "	~~ LITTLE ~~" << RESET << std::endl;
		Span sp1(5);
		std::vector<int> vec1;
		vec1.push_back(1);
		vec1.push_back(2);
		vec1.push_back(3);
		vec1.push_back(4);
		vec1.push_back(5);
		sp1.addRange(vec1.begin(), vec1.end());
		std::cout << BOLD << "Vector min : " << *std::min_element(vec1.begin(), vec1.end());
		std::cout << "	Vector max : " << *std::max_element(vec1.begin(), vec1.end()) << RESET << std::endl;
		std::cout << "Shortest Span: " << GREEN << sp1.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: " << GREEN << sp1.longestSpan() << RESET << std::endl << std::endl;


		std::cout << BLUE << "	~~ BIG ~~ " << RESET << std::endl;
		Span sp2(111111);
		std::vector<int> vec2;
		for (int i = 1; i <= 100000; ++i)
			vec2.push_back(i);
		sp2.addRange(vec2.begin(), vec2.end());
		std::cout << BOLD << "Vector min : " << *std::min_element(vec2.begin(), vec2.end());
		std::cout << "	Vector max : " << *std::max_element(vec2.begin(), vec2.end()) << RESET << std::endl;
		std::cout << "Shortest Span: " << GREEN << sp2.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: " << GREEN <<sp2.longestSpan() << RESET << std::endl << std::endl;

		std::cout << BLUE << "	~~ ERROR ~~ " << RESET << std::endl;
		Span sp3(3);
		std::vector<int> vec3;
		for (int i = 1; i <= 6; ++i)
			vec3.push_back(i);
		sp3.addRange(vec3.begin(), vec3.end());
		std::cout << BLUE << "Vector min : " << *std::min_element(vec3.begin(), vec3.end());
		std::cout << "	Vector max : " << *std::max_element(vec3.begin(), vec3.end()) << RESET << std::endl;
		std::cout << "Shortest Span: " << GREEN << sp3.shortestSpan() << RESET << std::endl;
		std::cout << "Longest Span: " << GREEN <<sp3.longestSpan() << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
