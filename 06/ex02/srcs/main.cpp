/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by bfresque          #+#    #+#             */
/*   Updated: 2024/04/10 17:21:01 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

int main()
{
	srand(time(NULL) ^ getpid());

	Base *p = generate();
	
	identify(p);
	identify(*p);
	
	delete p;
	return (0);
}