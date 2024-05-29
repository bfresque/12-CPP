/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:44:32 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/17 10:03:31 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define BOLD		"\033[1m\033[37m"
# define RESET		"\033[0m"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack() : std::stack<T>() { }
	MutantStack(const MutantStack& other) : std::stack<T>(other) { }
	MutantStack& operator=(const MutantStack& other) {
		std::stack<T>::operator=(other);
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin() { return (this->c.begin()); }
	iterator end() { return (this->c.end()); }
	
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	const_iterator begin() const { return (this->c.begin()); }
	const_iterator end() const { return (this->c.end()); }

};

#endif