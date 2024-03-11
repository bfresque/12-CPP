/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:08:27 by bfresque          #+#    #+#             */
/*   Updated: 2024/03/08 15:08:43 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongCat();
		WrongCat(const WrongCat &copy);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat();
		void	makeSound() const;
};

#endif
