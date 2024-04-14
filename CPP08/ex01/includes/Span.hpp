/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:44:32 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/14 21:11:03 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {
	private:
		unsigned int _rangeSize;
		std::vector<int> _container;

	public:
		Span();
		Span(unsigned int size);
		~Span();
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addNumber(unsigned int newNumber);
		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end);

		class numberAlreadySet : public std::exception {
			public:
				char const * what() const throw() {
					return "Adding this would exceed Span's capacity!";
				}
		};

		class containerIsEmpty : public std::exception {
			public:
				char const * what() const throw() {
					return "Container is empty!";
				}
		};

		class containerLengthIsOne : public std::exception {
			public:
				char const * what() const throw() {
					return "Container length is one!";
				}
		};
};

#endif