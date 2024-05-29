/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:44:32 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/17 09:48:06 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define INT_MAX 2147483647
# include <iostream>
# include <vector>
# include <algorithm>
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BOLD		"\033[1m\033[37m"
# define RESET		"\033[0m"

class Span {
	private:
		unsigned int _rangeSize;
		std::vector<int> _container;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const & other);
		Span &operator=(Span const & other);
		~Span();
		int		shortestSpan() const;
		int		longestSpan() const;
		void	addNumber(unsigned int newNumber);

		template <typename Iterator>
		void	addRange(Iterator begin, Iterator end) {
			unsigned int rangeSize = std::distance(begin, end);
			if ((_container.size() + rangeSize) > _rangeSize)
				throw Span::numberAlreadySet();

			while (begin != end) {
				_container.push_back(*begin);
				++begin;
			}
		}

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