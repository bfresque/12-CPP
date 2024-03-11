/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:34:12 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/09 11:43:10 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor called" <<std::endl;
	return;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy constructor called" <<std::endl;
	*this = copy;
	return;
}

Brain::~Brain()
{
	std::cout << "Brain Default destructor called" <<std::endl;
	return;
}

Brain	&Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignement operator called" << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

void	Brain::addIdeas(std::string newIdeas)
{
	for (int i = 0; i < 110; ++i)
	{
		if (i < 100)
			ideas[i] = newIdeas;
		else
		{
			std::cout << "Aaahh !!! Stop to put idea"<< std ::endl;
			std::cout << "My brain is full" << std ::endl;
			return;
		}
	}
	return;
}

void	Brain::readBrain() const
{
	for (int i = 0; i < 100; ++i)
		std::cout << ideas[i] << std::endl;
	return;
}
