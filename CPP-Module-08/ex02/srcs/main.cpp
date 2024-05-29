/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/17 10:10:38 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

int main() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << BLUE << " ~~ VERIF POP ~~" << RESET << std::endl;
	std::cout << "Top element avant pop : " << mstack.top() << std::endl;
	// ajouter aussi la size avant et apres le poop !!?
	mstack.pop();
	std::cout << "Top element after pop : " << mstack.top() << std::endl << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(42);

	std::cout << BLUE << " ~~ VERIF CLASSIC ~~" << RESET << std::endl;
	std::cout << "Stack elements: ";
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	
	std::cout << BLUE << " ~~ VERIF CONST ~~" << RESET << std::endl;
	const MutantStack<int> cmstack(mstack);
	std::cout << "Const Stack elements: ";
	for (MutantStack<int>::const_iterator it = cmstack.begin(); it != cmstack.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << BLUE << " ~~ VERIF COPY ~~" << RESET << std::endl;
	MutantStack<int> copiedStack(mstack);
	std::cout << "Copied stack top element: " << copiedStack.top() << std::endl << std::endl;

	MutantStack<int> assignedStack;
	assignedStack = mstack;
	std::cout << BLUE << " ~~ VERIF ASSIGNEMENT ~~" << RESET << std::endl;
	std::cout << "Assigned stack top element: " << assignedStack.top() << std::endl << std::endl;

	std::cout << BLUE << " ~~ VERIF STRING ~~" << RESET << std::endl;
	MutantStack<std::string> stringStack;
	stringStack.push("Hello");
	stringStack.push("World");
	std::cout << "Top string in stack: " << stringStack.top() << std::endl << std::endl;

	std::cout << BLUE << " ~~ VERIF EMPTY ~~" << RESET << std::endl;
	MutantStack<int> emptyStack;
	if (!emptyStack.empty())
		std::cout << "Attempting to access top element of an non-empty stack: " << emptyStack.top() << std::endl;
	else
		std::cout << "Cannot access top element of an empty stack." << std::endl;
	return (0);
}
