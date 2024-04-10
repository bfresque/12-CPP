/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 10:10:23 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 17:20:24 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	switch (rand() % 3) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C(); }
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL) std::cout << "A\n";
	else if (dynamic_cast<B*>(p) != NULL) std::cout << "B\n";
	else if (dynamic_cast<C*>(p) != NULL) std::cout << "C\n";
}

void identify(Base& p)
{
	if (dynamic_cast<A*>(&p) != NULL) std::cout << "A\n";
	else if (dynamic_cast<B*>(&p) != NULL) std::cout << "B\n";
	else if (dynamic_cast<C*>(&p) != NULL) std::cout << "C\n";
}