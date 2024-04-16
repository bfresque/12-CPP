/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/16 17:36:26 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

#include <string>

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Top element after pop: " << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Stack elements: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	const MutantStack<int> cmstack(mstack);
	std::cout << "Const Stack elements: ";
	for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	MutantStack<int> copiedStack(mstack);
	std::cout << "Copied stack top element: " << copiedStack.top() << std::endl;

	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << "Assigned stack top element: " << assignedStack.top() << std::endl;

	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	std::cout << "Top string in stack: " << stringStack.top() << std::endl;

	MutantStack<int> emptyStack;
	if (!emptyStack.empty())
		std::cout << "Attempting to access top element of an non-empty stack: " << emptyStack.top() << std::endl;
	else
		std::cout << "Cannot access top element of an empty stack." << std::endl;
	return (0);
}
