/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:30:36 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/12 11:10:58 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include<iostream>
# include "./Brain.hpp"

# define LINE "--------------------------------"

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string& type);
		AAnimal(const AAnimal& copy);
		AAnimal& operator=(const AAnimal& other);
		virtual ~AAnimal();
		virtual Brain* getBrain(void) const;
		std::string getType() const;

		virtual void makeSound() const = 0;
};

#endif
